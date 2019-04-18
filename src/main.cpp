#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <tuple>

#include "Course.h"
#include "Section.h"
#include "Teacher.h"
#include "Student.h"
#include "Functions.h"

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

    Functions function;

    int periodsInDay;
    int classSize;
    int reqPreps;
    bool AB;

    fstream fileHandler;

    void studentSetUp(string);
    void teacherSetUp(string);
    void classSetUp(string);
    void assignStudents();
    void initialSplit();
    void assignTeachers();
    void assignSections();
    void writeSchedule(string, string);
    string itos(int);


};

int main() {
    Application app;
    app.run();
    cout << "Hello, World!" << std::endl;
}

Application::Application() {
    periodsInDay = 8;
    classSize = 30;
    studentSetUp("Data/students.txt");
    teacherSetUp("Data/teachers.txt");
    classSetUp("Data/courses.txt");
}

void Application::run(){
    assignStudents();
    assignTeachers();
    function.quicksort(&courses[0],0,courses.size()-1);
    assignSections();
    writeSchedule("Data/schedule.txt", "Data/studentSchedule.txt");


}

void Application::assignSections() {
    for(int i = 0; i < courses.size(); i++){
        int numSections = courses[i].getNumStudents()/classSize + 1;
        vector<int> availablePeriods;
        for(int j = 0; j < courses[i].getNumTeachers(); j++){
            for(int k = 0; k < periodsInDay; k++){
                if((&teachers[0]+courses[i].getTeachers()[j])->getSchedule()[k] == " "){
                    bool before = false;
                    for(int h = 0; h < availablePeriods.size(); h++){
                        before = k == availablePeriods[h]? true : false;
                    }
                    if(!before){
                        availablePeriods.push_back(k);
                    }
                }
            }
        }
        vector<tuple<int,int> > studentAvail;
        for(int j = 0; j < availablePeriods.size(); j++){
            studentAvail.push_back(make_tuple(availablePeriods[j],0));
        }
        for(int j = 0; j < courses[i].getNumStudents(); j++){
            for(int k = 0; k < availablePeriods.size(); k++){
                get<1>(studentAvail[k]) = (&students[0]+courses[i].getStudents()[j])->getSchedule()[availablePeriods[k]] == " " ? get<1>(studentAvail[k])+1:get<1>(studentAvail[k]);
            }
        }
        function.quicksort(&studentAvail[0],0,studentAvail.size()-1);
        for(int j = 0; j < numSections; j++){
            bool found = false;
            for(int k = 0; k < courses[i].getNumTeachers() && !found; k++){
                for(int l = 0; l < studentAvail.size() && !found; l++){
                    if((&teachers[0]+courses[i].getTeachers()[k])->getSchedule()[get<0>(studentAvail[l])] == " ") {
                        sections.push_back(Section(courses[i].getId() + (char) ('0' + j), courses[i].getId(), &teachers[0] + courses[i].getTeachers()[k], &students[0], get<0>(studentAvail[l])));
                        (&teachers[0] + courses[i].getTeachers()[k])->getSchedule()[get<0>(studentAvail[l])] = (string) (courses[i].getId() + (char) ('0' + j));
                        found = true;
                    }
                }
            }
        }
        cout << "Teacher Assign" << endl;
        for(int j = 0; j < courses[i].getStudents().size(); j++){
            vector<int> avail;
            for(int  k = 0; k < studentAvail.size(); k++){
                if((&students[0]+courses[i].getStudents()[j])->getSchedule()[get<0>(studentAvail[k])] == " "){
                    avail.push_back(k);
                }
            }
            if(avail.size() > 0){
                int smallest = -1;
                for(int l = 0; l < avail.size(); l++){
                    for(int m = 0; m < sections.size(); m++){
                        if(sections[m].getCourse() == courses[i].getId() && sections[m].getPeriod() == avail[l]){
                            if(smallest == -1){
                                smallest = m;
                            }else if(sections[m].getStudent().size() < sections[smallest].getStudent().size()){
                                smallest = m;
                            }
                        }
                    }
                }
                if(smallest != -1){
                    sections[smallest].addStudent(courses[i].getStudents()[j]);
                    (&students[0]+courses[i].getStudents()[j])->getSchedule()[sections[smallest].getPeriod()] = sections[smallest].getId();
                }
            }
        }
        cout << "Student Assign" << endl;
    }
}

void Application::studentSetUp(string fileName) {
    string line;
    fileHandler.open(fileName);
    if(fileHandler.is_open())
    {
        while (getline(fileHandler,line))
        {
            vector<string> student;

            stringstream lineStream(line);
            string cell;
            while(getline(lineStream,cell,','))
            {
                student.push_back(cell);
            }
            string id = student[0];
            student.erase(student.begin());
            students.push_back(Student(id, student, periodsInDay));
        }
    }
    fileHandler.close();
}

void Application::teacherSetUp(string fileName) {
    string line;
    fileHandler.open(fileName);
    if(fileHandler.is_open())
    {
        while (getline(fileHandler,line))
        {
            vector<string> teacher;

            stringstream lineStream(line);
            string cell;
            while(getline(lineStream,cell,','))
            {
                teacher.push_back(cell);
            }
            string id = teacher[0];
            teacher.erase(teacher.begin());
            teachers.push_back(Teacher(id, teacher, periodsInDay));
        }
    }
    fileHandler.close();

}

void Application::classSetUp(string fileName){
    fileHandler.open(fileName);
    string line;
    if(fileHandler.is_open())
    {
        while (getline(fileHandler,line))
        {
            courses.push_back(Course(line, &students[0], &teachers[0]));
        }
    }
    fileHandler.close();
}

void Application::assignTeachers() {
    for(int i = 0; i < courses.size(); i++)
    {
        for(int j = 0; j < teachers.size(); j++)
        {
            for(string qual : teachers[j].getQualifications())
            {
                if(courses[i].getId() == qual)
                {
                    courses[i].addTeacher(j);
                }
            }
        }

    }

}


void Application::assignStudents()
{
    for(int i = 0; i < courses.size(); i++)
    {
        for(int j = 0; j < students.size(); j++)
        {
            for(string request : students[j].getRequests())
            {
                if(courses[i].getId() == request)
                {
                    courses[i].addStudent(j);
                }
            }
        }
    }

}

void Application::writeSchedule(string filenameA, string filenameB){
    ofstream myFile;
    myFile.open(filenameA);
    for(int i = 0; i < sections.size(); i++){
        myFile << sections[i].getCourse() << ", " << sections[i].getId() << ", " << sections[i].getPeriod() << ", "  << sections[i].getStudent().size() << endl;
        for(int j = 0; j < sections[i].getStudent().size(); j++){
            myFile << (&students[0]+sections[i].getStudent()[j])->getId() << ", ";
        }
        myFile << endl;

    }
    myFile.close();
    myFile.open(filenameB);
    for(int i = 0; i < students.size(); i++){
        myFile << students[i].getId() << ", ";
        for(int j = 0; j < students[i].getSchedule().size(); j++){
            myFile << students[i].getSchedule()[j] << ", ";
        }
        myFile << endl;
    }
    myFile.close();
}



string Application::itos(int a){
    stringstream ss;
    ss << a;
    return ss.str();
}