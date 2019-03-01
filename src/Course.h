//
// Created by joshu on 19/02/04.
//

#ifndef FORECASTINGALGORITHM_COURSE_H
#define FORECASTINGALGORITHM_COURSE_H

#include <vector>
#include <String>
#include "Section.h"
#include "Student.h"
#include "Teacher.h"

class Course {
public:
    Course(string, vector<Teacher>, vector<Student>);
    Course(string);

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
    const vector<Teacher> &getTeachers() const;
    void setTeachers(const vector<Teacher> &teachers);
    const vector<Student> &getStudents() const;
    void setStudents(const vector<Student> &students);

private:
    string id;
    int numSections, numTeachers, numStudents;
    vector<Section> sections;
    vector<Teacher> teachers;
    vector<Student> students;
};

Course::Course(string id, vector<Teacher> teachers, vector<Student> studnets){
    Course::id = id;
    for(Teacher teacher: teachers){
        Course::teachers.push_back(teacher);
    }
    numTeachers = Course::teachers.size();
    for(Student student : studnets){
        Course::students.push_back(student);
    }
    numStudents = Course::students.size();
}

Course::Course(string id){
    Course::id = id;
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

const vector<Teacher> &Course::getTeachers() const {
    return teachers;
}

void Course::setTeachers(const vector<Teacher> &teachers) {
    Course::teachers = teachers;
}

const vector<Student> &Course::getStudents() const {
    return students;
}

void Course::setStudents(const vector<Student> &students) {
    Course::students = students;
}


#endif //FORECASTINGALGORITHM_COURSE_H
