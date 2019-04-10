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
    Student(string, vector<string>, int);

    const string &getId() const;
    void setId(const string &id);
    const vector<string> &getRequests() const;
    void setRequests(const vector<string> &requests);
    vector<string> getSchedule();
    void setSchedule(const vector<string> &schedule);

private:
    string id;
    vector<string> requests;
    vector<string> schedule;
};

Student::Student(string id, vector<string> requests, int periods){
    Student::id = id;
    for(string request : requests){
        Student::requests.push_back(request);
    }
    for(int i = 0; i < periods; i++){
        schedule.push_back(" ");
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

vector<string> Student::getSchedule()  {
    return schedule;
}

void Student::setSchedule(const vector<string> &schedule) {
    Student::schedule = schedule;
}


#endif //FORECASTINGALGORITHM_STUDENT_H
