//
// Created by Julio Sandino on 11/6/16.
//

#ifndef P4_CCOURSES_H
#define P4_CCOURSES_H

#include <iostream>
#include <string>
using namespace std;


const int NUMBER_OF_STUDENTS = 5;

class CCourse {
public:
    //data members
    string CRN;
    string Title;
    int units;
	string students[NUMBER_OF_STUDENTS];

    //constructors
    CCourse();
    CCourse(string CRN, string Title, int Units, int NumberOfStudents);
    CCourse(const CCourse& course);
    ~CCourse();

    //accesor and mutator
    void setNumberOfStudents(int num);
    int getNumberOfStudents();

    //operator overloading functions
    friend istream&operator >> (istream& ins, CCourse& course);
    friend ostream&operator << (ostream& outs, CCourse& course);

private:
    int NumberOfStudents;
};


#endif //P4_CCOURSES_H
