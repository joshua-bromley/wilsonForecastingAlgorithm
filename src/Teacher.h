//
// Created by joshu on 19/01/31.
//

#ifndef FORECASTINGALGORITHM_TEACHER_H
#define FORECASTINGALGORITHM_TEACHER_H

#include <string>
#include <vector>

using namespace std;

class Teacher {
public:
    Teacher(string, vector<string>);
    Teacher();

    const string &getId() const;
    void setId(const string &id);
    const vector<string> &getQualifications() const;
    void setQualifications(const vector<string> &qualifications);
    const vector<string> &getSchedule() const;
    void setSchedule(const vector<string> &schedule);
private:
    string id;
    vector<string> qualifications;
    vector<string> schedule;

};

Teacher::Teacher(string id, vector<string> qualifications){
    Teacher::id = id;
    for(string qualification : qualifications){
        Teacher::qualifications.push_back(qualification);
    }
}

Teacher::Teacher(){

}

const string &Teacher::getId() const {
    return id;
}

void Teacher::setId(const string &id) {
    Teacher::id = id;
}

const vector<string> &Teacher::getQualifications() const {
    return qualifications;
}

void Teacher::setQualifications(const vector<string> &qualifications) {
    Teacher::qualifications = qualifications;
}

const vector<string> &Teacher::getSchedule() const {
    return schedule;
}

void Teacher::setSchedule(const vector<string> &schedule) {
    Teacher::schedule = schedule;
}


#endif //FORECASTINGALGORITHM_TEACHER_H
