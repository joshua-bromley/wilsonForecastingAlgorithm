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

    int periodsInDay;
    int reqPreps;
    bool AB;

    fstream fileHandler;

    void studentSetUp(string);
    void teacherSetUp(string);

};

int main() {
    cout << "Hello, World!" << std::endl;
    return 0;
}

Application::Application() {

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