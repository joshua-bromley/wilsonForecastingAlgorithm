#include <iostream>
#include <fstream>
#include <sstream>
#include <Vector>
#include <String>
#include <math.h>

using namespace std;

class schedule
{
public:
    vector<string> classes;
    vector<int> classnum;
    vector<vector<int>> division;
    vector<vector<string>> requests;

    string line;
    int classSize = 10;

    void counter();
    void initialSplit();
};

void schedule::counter()
{
    for(int ii = 0; ii < classes.size(); ii++)
    {
        for(int jj = 0; jj < requests.size(); jj++)
        {
            for(int qq = 0; qq < requests[jj].size(); qq++)
            {
                if(classes[ii] == requests[jj][qq])
                {
                    classnum[ii]++;
                }
            }
        }
    }

    for(int ii = 0; ii < classnum.size(); ii++)
    {
        cout << classnum[ii] << " ";
    }
     cout << endl;
}

void schedule::initialSplit()
{
    for(int ii = 0; ii < classnum.size(); ii++)
    {
        vector<int> classTotals;

        int roundClasses = (classnum[ii]/classSize) + (classnum[ii] % classSize != 0);

        if(roundClasses != 0)
        {
            classTotals.push_back(roundClasses);

            if(classnum[ii]%roundClasses != 0)
            {
                for(int qq = 0; qq < roundClasses-1; qq++)
                {
                    int tempclass = classnum[ii]/roundClasses;

                    classTotals.push_back(tempclass);
                }
                classTotals.push_back((classnum[ii]/roundClasses)+(classnum[ii]%roundClasses));
            }
            else
            {
                for(int qq = 0; qq < roundClasses; qq++)
                {
                    int tempclass = classnum[ii]/roundClasses;
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

int main()
{
    schedule New;

    string line;

    ifstream myfile ("classes.csv");
    if(myfile.is_open())
    {
        while (getline(myfile,line))
        {
            New.classes.push_back(line);
            New.classnum.push_back(0);
        }
    }

    ifstream requestfile ("request.csv");
    if(requestfile.is_open())
    {
        while (getline(requestfile,line))
        {
            vector<string> student;

            stringstream lineStream(line);
            string cell;
            while(getline(lineStream,cell,','))
            {
                student.push_back(cell);
            }
            New.requests.push_back(student);
        }
    }

    New.counter();
    New.initialSplit();
}


