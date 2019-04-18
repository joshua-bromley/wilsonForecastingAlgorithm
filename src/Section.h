//
// Created by joshu on 19/02/04.
//

#ifndef FORECASTINGALGORITHM_SECTION_H
#define FORECASTINGALGORITHM_SECTION_H

#include <Vector>
#include <String>
#include "Student.h"
#include "Teacher.h"

using namespace std;

class Section {
public:
    Section(string, string, Teacher*, Student*, int);
    Section(string, string, Student* ,vector<int>);

    string getId();

    void setId(const string &id);

    const string &getCourse() const;

    void setCourse(const string &course);

    int getPeriod() const;

    void setPeriod(int period);

    vector<int> &getStudent();

    void addStudent(int);




private:
    string id;
    string course;
    int period;
    Teacher* teacher;
    Student* headStudent;
    vector<int> students;
};

Section::Section(string id, string course, Teacher* teacher, Student* headStudent, int period){
    Section::id = id;
    Section::course = course;
    Section::teacher = teacher;
    Section::period = period;
    Section::headStudent = headStudent;
}

Section::Section(string id, string course, Student* headStudent,vector<int> students){
    Section::id = id;
    Section::course = course;
    Section::headStudent = headStudent;
    for(int student : students){
        Section::students.push_back(student);
    }
}

string Section::getId() {
    return id;
}

void Section::setId(const string &id) {
    Section::id = id;
}

const string &Section::getCourse() const {
    return course;
}

void Section::setCourse(const string &course) {
    Section::course = course;
}

int Section::getPeriod() const {
    return period;
}

void Section::setPeriod(int period) {
    Section::period = period;
}

vector<int> &Section::getStudent(){ return students;}


void Section::addStudent(int student){
    students.push_back(student);
}





#endif //FORECASTINGALGORITHM_SECTION_H
