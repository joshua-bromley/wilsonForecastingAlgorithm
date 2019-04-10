//
// Created by joshu on 19/03/17.
//

#ifndef FORECASTINGALGORITHM_FUNCTIONS_H
#define FORECASTINGALGORITHM_FUNCTIONS_H

#include "Course.h"
#include <tuple>

class Functions{
public:
    void quicksort(Course* , int, int);
    void quicksort(tuple<int,int>*, int,int);
private:
    int partition(Course* , int, int);
    int partition(tuple<int,int>*, int, int);
    void swap(Course*, Course*);
    void swap(tuple<int,int>*, tuple<int,int>*);

};

void Functions::quicksort(Course* head, int low, int high) {
    if(low < high){
        int pi = partition(head, low, high);
        quicksort(head,low,pi-1);
        quicksort(head,pi+1,high);
    }
}

void Functions::quicksort(tuple<int,int>* head, int low, int high) {
    if(low < high){
        int pi = partition(head, low, high);
        quicksort(head,low,pi-1);
        quicksort(head,pi+1,high);
    }
}

int Functions::partition (Course* head, int low, int high)
{
    int pivot = (head+high)->getNumTeachers()*10000 + (head+high)->getNumStudents();    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if ((head+j)->getNumTeachers()*10000 + (head+j)->getNumStudents() <= pivot)
        {
            i++;    // increment index of smaller element
            swap(head+i, head+j);
        }
    }
    swap(head+i+1, head+high);
    return (i + 1);
}

int Functions::partition (tuple<int,int>* head, int low, int high)
{
    int pivot = get<1>(*(head+high));    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (get<1>(*(head+j)) <= pivot)
        {
            i++;    // increment index of smaller element
            swap(head+i, head+j);
        }
    }
    swap(head+i+1, head+high);
    return (i + 1);
}

void Functions::swap(Course* a, Course* b){
    Course c = *a;
    *a = *b;
    *b = c;
}

void Functions::swap(tuple<int,int>* a, tuple<int,int>* b){
    tuple<int,int> c = *a;
    *a = *b;
    *b = c;
}

#endif //FORECASTINGALGORITHM_FUNCTIONS_H
