//
// Created by Julio Sandino on 11/1/16.
//

#include "CCourse.h"
#include <iostream>
using namespace std;

CCourse::CCourse() {
    CRN = "Z000";
    Title = "None";
    Units = 0;
    NumberOfStudents = 0;
}

CCourse::CCourse(string CRN, string Title, int Units, int NumberOfStudents) {
    this->CRN = CRN;
    this->Title = Title;
    this->Units = Units;
    this->NumberOfStudents = NumberOfStudents;
}

CCourse::CCourse(const CCourse &CCourse) {
    CRN = CCourse.CRN;
    Title = CCourse.Title;
    Units = CCourse.Units;
    NumberOfStudents = CCourse.NumberOfStudents;
}

CCourse::~CCourse() {}

void CCourse::showInfo() {
    cout << "CRN: " << CRN << endl
            << "Title: " << Title << endl
            << "Units: " << Units << endl
            << "Number of Students: " << getNumberOfStudents() << endl;
}

void CCourse::getInfo() {
    cout << "CRN of the class > ";
    cin >> CRN;
    cout << "Title of class > ";
    cin >> Title;
    cout <<  "Number of units > ";
    cin >> Units;
    int students;
    cout << "Number of students in class > ";
    cin >> students;
    setNumberOfStudents(students);
}

int CCourse::getNumberOfStudents() {
    return NumberOfStudents;
}

void CCourse::setNumberOfStudents(int students) {
    NumberOfStudents = students;
}



