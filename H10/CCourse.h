//
// Created by Julio Sandino on 10/27/16.
//
#ifndef H10_CCOURSE_H
#define H10_CCOURSE_H

#include <string>
using namespace std;

class CCourse{

public:
    string CRN;
    string Title;
    int Units;

    CCourse();
    CCourse(string CRN, string Title, int Units, int NumberOfStudents);
    CCourse(const CCourse& CCourse);
    ~CCourse();

    friend istream&operator >> (istream& ins, CCourse& course);
    friend ostream&operator << (ostream& outs, CCourse& course);

    void getInfo();
    void showInfo();

    int getNumberOfStudents();
    void setNumberOfStudents(int students);

private:
    int NumberOfStudents;
};
#endif //H10_CCOURSE_H
