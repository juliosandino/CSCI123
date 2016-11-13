//
// Created by Julio Sandino on 11/6/16.
//

#ifndef P4_CSTUDENTINFO_H
#define P4_CSTUDENTINFO_H

#include <iostream>
#include <string>
using namespace std;

//setpixel helped me out here. 10/10
enum YearTerm {UNKNOWN = 0, FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};

class CStudentInfo {
public:
    //Data Members
    string ID;
    string firstName;
    char middleInitial;
    string lastName;
    int units;
	string classes[5];

    //Constructors
    CStudentInfo();
    CStudentInfo(string ID, string firstName, char middleInitial, string lastName, int units, int term);
    CStudentInfo(const CStudentInfo& student);
    ~CStudentInfo();

    //operators
    friend ostream&operator <<(ostream& outs, CStudentInfo& student);
    friend istream&operator >>(istream& ins, CStudentInfo& student);

    void setTerm(int term);
    YearTerm getTerm();

    string termToString();

private:
    YearTerm Term;
};


#endif //P4_CSTUDENTINFO_H
