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
    Section(string, string);

    const string &getId() const;

    void setId(const string &id);

    const string &getCourse() const;

    void setCourse(const string &course);

    int getPeriod() const;

    void setPeriod(int period);

    const Teacher &getTeacher() const;

    void setTeacher(const Teacher &teacher);

    const vector<Student> &getStudents() const;

    void setStudents(const vector<Student> &students);

private:
    string id;
    string course;
    int period;
    Teacher teacher;
    vector<Student> students;
};

Section::Section(string id, string course){
    Section::id = id;
    Section::course = course;
}

const string &Section::getId() const {
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

const Teacher &Section::getTeacher() const {
    return teacher;
}

void Section::setTeacher(const Teacher &teacher) {
    Section::teacher = teacher;
}

const vector<Student> &Section::getStudents() const {
    return students;
}

void Section::setStudents(const vector<Student> &students) {
    Section::students = students;
}


#endif //FORECASTINGALGORITHM_SECTION_H
