//
// Created by joshu on 19/02/04.
//

#ifndef FORECASTINGALGORITHM_COURSE_H
#define FORECASTINGALGORITHM_COURSE_H

#include <vector>
#include <String>
#include <iostream>
#include "Section.h"
#include "Student.h"
#include "Teacher.h"

class Course {
public:
    Course(string, vector<int>, vector<int>, Student*, Teacher*);
    Course(string, Student*, Teacher*);

    const string &getId() const;
    void setId(const string &id);
    int getNumSections() const;
    void setNumSections(int numSections);
    int getNumTeachers() const;
    void setNumTeachers(int numTeachers);
    int getNumStudents() const;
    void setNumStudents(int numStudents);
    const vector<Section> &getSections() const;
    void setSections(const vector<Section> &sections);
    vector<int> getTeachers();
    vector<int> getStudents();
    void addStudent(int);
    void addTeacher(int);


private:
    string id;
    int numSections, numTeachers, numStudents;
    vector<Section> sections;
    Teacher* headTeacher;
    Student* headStudent;
    vector<int> teachers;
    vector<int> students;
};

Course::Course(string id, vector<int> teachers, vector<int> students, Student* headStudent, Teacher* headTeacher){
    Course::id = id;
    for(int teacher: teachers){
        Course::teachers.push_back(teacher);
    }
    numTeachers = Course::teachers.size();
    for(int student : students){
        Course::students.push_back(student);
    }
    numStudents = Course::students.size();
    Course::headStudent = headStudent;
    Course::headTeacher = headTeacher;
}

Course::Course(string id, Student* headStudent, Teacher* headTeacher){
    Course::id = id;
    Course::headStudent = headStudent;
    Course::headTeacher = headTeacher;
    numStudents = 0;
    numTeachers = 0;
    numSections = 0;
}

const string &Course::getId() const {
    return id;
}

void Course::setId(const string &id) {
    Course::id = id;
}

int Course::getNumSections() const {
    return numSections;
}

void Course::setNumSections(int numSections) {
    Course::numSections = numSections;
}

int Course::getNumTeachers() const {
    return numTeachers;
}

void Course::setNumTeachers(int numTeachers) {
    Course::numTeachers = numTeachers;
}

int Course::getNumStudents() const {
    return numStudents;
}

void Course::setNumStudents(int numStudents) {
    Course::numStudents = numStudents;
}

const vector<Section> &Course::getSections() const {
    return sections;
}

void Course::setSections(const vector<Section> &sections) {
    Course::sections = sections;
}



void Course::addStudent(int student) {
    students.push_back(student);
    numStudents++;
}

void Course::addTeacher(int teacher) {
    teachers.push_back(teacher);
    numTeachers++;
}

vector<int> Course::getTeachers() { return teachers;}


vector<int> Course::getStudents() {return students;}



#endif //FORECASTINGALGORITHM_COURSE_H
