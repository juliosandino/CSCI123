//main.cpp
//Programmer: Julio Sandino                                             CSCI 123, Fall 2016
//Project 5                                                             Instructor: Mai, Timothy
//Due Date: 12/1/16                                    Date Submitted: 12/1/16

//Program Description:
//This program will be able to log student info and course info in a college enrollment system
//it will read from a file and output to that file
//it will employ multiple classes, and will be interactive with the user.
//It will work just as any other enrollment system would work

#include <iostream>
#include "CEnrollmentSystem.h"
using namespace std;

int main() {
    CEnrollmentSystem enrollmentSystem;
    enrollmentSystem.EnrollSystem();
    return 0;
}

