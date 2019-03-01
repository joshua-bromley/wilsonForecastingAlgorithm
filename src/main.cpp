#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Course.h"
#include "Section.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;

class Application{
public:
    Application();
    void run();
private:
    vector<Course> courses;
    vector<Section> sections;
    vector<Teacher> teachers;
    vector<Student> students;
    vector<vector<int>> division;


    int periodsInDay;
    int classSize;
    int reqPreps;
    bool AB;

    fstream fileHandler;

    void studentSetUp(string);
    void teacherSetUp(string);
    void classSetUp(string);
    void counter();
    void initialSplit();

};

int main() {
    cout << "Hello, World!" << std::endl;
    return 0;
}

Application::Application() {
    classSize = 10;
}

void Application::run(){

}

void Application::studentSetUp(string fileName) {
    fileHandler.open(fileName);
    while(!fileHandler.eof()){
        string id;
        vector<string> requests;
        getline(fileHandler, id, ',');
        while(fileHandler.get() != '\n'){
            string request;
            getline(fileHandler,request,',');
            requests.push_back(request);
        }
        students.push_back(Student(id,requests));
    }

}

void Application::teacherSetUp(string fileName) {
    fileHandler.open(fileName);
    while(!fileHandler.eof()){
        string id;
        vector<string> qualifications;
        getline(fileHandler, id, ',');
        while(fileHandler.get() != '\n'){
            string qualification;
            getline(fileHandler,qualification,',');
            qualifications.push_back(qualification);
        }
        teachers.push_back(Teacher(id,qualifications));
    }

}

void Application::classSetUp(string fileName){
    fileHandler.open(fileName);
    string line;
    if(fileHandler.is_open())
    {
        while (getline(fileHandler,line))
        {
            courses.push_back(Course(line));
        }
    }
}

void Application::counter()
{
    for(int ii = 0; ii < courses.size(); ii++)
    {
        for(int jj = 0; jj < courses.size(); jj++)
        {
            for(int qq = 0; qq < students[jj].getRequests().size(); qq++)
            {
                if(courses[ii].getId() == students[jj].getRequests()[qq])
                {
                    courses[ii].setNumStudents(courses[ii].getNumStudents()+1);
                }
            }
        }
    }

    for(int ii = 0; ii < courses.size(); ii++)
    {
        cout << courses[ii].getNumStudents() << " ";
    }
    cout << endl;
}

void Application::initialSplit()
{
    for(int ii = 0; ii < courses.size(); ii++)
    {
        vector<int> classTotals;

        int roundClasses = (courses[ii].getNumStudents()/classSize) + (courses[ii].getNumStudents() % classSize != 0);

        if(roundClasses != 0)
        {
            classTotals.push_back(roundClasses);

            if(courses[ii].getNumStudents()%roundClasses != 0)
            {
                for(int qq = 0; qq < roundClasses-1; qq++)
                {
                    int tempclass = courses[ii].getNumStudents()/roundClasses;

                    classTotals.push_back(tempclass);
                }
                classTotals.push_back((courses[ii].getNumStudents()/roundClasses)+(courses[ii].getNumStudents()%roundClasses));
            }
            else
            {
                for(int qq = 0; qq < roundClasses; qq++)
                {
                    int tempclass = courses[ii].getNumStudents()/roundClasses;
                    classTotals.push_back(tempclass);
                }
            }
        }
        else
        {
            classTotals.push_back(0);
        }
        division.push_back(classTotals);
    }

    for(int ii = 0; ii < division.size(); ii++)
    {
        for(int jj = 0; jj < division[ii].size(); jj++)
        {
            cout << division[ii][jj] << " ";
        }
    }
}