//
// Created by Julio Sandino on 11/1/16.
//

#include "CStudentInfo.h"
#include <iostream>
using namespace std;

CStudentInfo::CStudentInfo() {
    ID = "Z9999";
    FirstName = "None";
    MiddleInitial = '?';
    LastName = "None";
    Units = 0;
    Term = UNKNOWN;
}

CStudentInfo::CStudentInfo(string ID, string fName, char mInitial, string Lname, int U, int term) {
    this->ID = ID;
    FirstName = fName;
    MiddleInitial = mInitial;
    LastName = Lname;
    Units = U;

    switch (term) {
        case 1:
            Term = FRESHMAN;
            break;
        case 2:
            Term = SOPHOMORE;
            break;
        case 3:
            Term = JUNIOR;
            break;
        case 4:
            Term = SENIOR;
            break;
        default:
            Term = UNKNOWN;
            break;
    }
}

CStudentInfo::CStudentInfo(const CStudentInfo &Student) {
    ID = Student.ID;
    FirstName = Student.FirstName;
    MiddleInitial = Student.MiddleInitial;
    LastName = Student.LastName;
    Units = Student.Units;
    Term = Student.Term;
}

CStudentInfo::~CStudentInfo() {}

void CStudentInfo::getInfo() {
    cout << "Student ID > ";
    cin >> ID;
    cout << "Student First Name > ";
    cin >> FirstName;
    cout << "Student Middle Initial > ";
    cin >> MiddleInitial;
    cout << "Student Last Name > ";
    cin >> LastName;
    cout << "Number of Units enrolled > ";
    cin >> Units;
    int term;
    cout << "Year Term of the student(as int) > ";
    cin >> term;
    switch (term) {
        case 1:
            setTerm(FRESHMAN);
            break;
        case 2:
            setTerm(SOPHOMORE);
            break;
        case 3:
            setTerm(JUNIOR);
            break;
        case 4:
            setTerm(SENIOR);
            break;
        default:
            setTerm(UNKNOWN);
            break;
    }
}

void CStudentInfo::showInfo() {
    cout << "ID: " << ID << endl
            << "First Name: " << FirstName << endl
            << "Middle Initial: " << MiddleInitial << endl
            << "Last Name: " << LastName << endl
            << "Units Enrolled: " << Units << endl
            << "Term: " << getTerm() << endl;
}

CStudentInfo::YearTerm CStudentInfo::getTerm() {
    return Term;
}

void CStudentInfo::setTerm(int term) {
    switch (term) {
        case 1:
            Term = FRESHMAN;
            break;
        case 2:
            Term = SOPHOMORE;
            break;
        case 3:
            Term = JUNIOR;
            break;
        case 4:
            Term = SENIOR;
            break;
        default:
            Term = UNKNOWN;
            break;
    }
}

