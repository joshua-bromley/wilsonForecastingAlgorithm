//
// Created by joshu on 19/01/31.
//

#ifndef FORECASTINGALGORITHM_STUDENT_H
#define FORECASTINGALGORITHM_STUDENT_H

#include <vector>
#include <string>

using namespace std;

class Student {
public:
    Student(string, vector<string>);

    const string &getId() const;
    void setId(const string &id);
    const vector<string> &getRequests() const;
    void setRequests(const vector<string> &requests);
    const vector<string> &getSchedule() const;
    void setSchedule(const vector<string> &schedule);

private:
    string id;
    vector<string> requests;
    vector<string> schedule;
};

Student::Student(string id, vector<string> requests){
    Student::id = id;
    for(string request : requests){
        Student::requests.push_back(request);
    }
}

const string &Student::getId() const {
    return id;
}

void Student::setId(const string &id) {
    Student::id = id;
}

const vector<string> &Student::getRequests() const {
    return requests;
}

void Student::setRequests(const vector<string> &requests) {
    Student::requests = requests;
}

const vector<string> &Student::getSchedule() const {
    return schedule;
}

void Student::setSchedule(const vector<string> &schedule) {
    Student::schedule = schedule;
}


#endif //FORECASTINGALGORITHM_STUDENT_H
