//
// Created by Julio Sandino on 10/27/16.
//

#include <iostream>
#include <string>
using namespace std;

#ifndef H10_CSTUDENTINFO_H
#define H10_CSTUDENTINFO_H


class CStudentInfo {

    enum YearTerm {UNKNOWN = 0, FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};
public:
    string ID;
    string FirstName;
    char MiddleInitial;
    string LastName;
    int Units;

    CStudentInfo();
    CStudentInfo(string ID, string fName, char mInitial, string Lname, int U, int term);
    CStudentInfo(const CStudentInfo& Student);
    ~CStudentInfo();

    friend istream&operator >> (istream& ins, CStudentInfo& student);
    friend ostream&operator << (ostream& outs, CStudentInfo& student);

    void getInfo();
    void showInfo();
    string termToString();

    YearTerm getTerm();
    void setTerm(int term);
private:
    YearTerm Term;
};

#endif //H10_CSTUDENTINFO_H
