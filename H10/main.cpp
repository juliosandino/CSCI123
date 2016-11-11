#include <iostream>
#include "CStudentInfo.h"
#include "CCourse.h"
using namespace std;

int main() {
    CCourse firstCourse;
    cout<< "The default information of the first Course: \n";
    cout << firstCourse;
    cout << "\n";
    cout << "(CRN, Title, Units, # of enrolled students)" << endl;
    cout << "Please enter the information for the class: ";
    cin >> firstCourse;
    cout << "\n";
    cout<< "The inputted information of the first Course: \n";
    cout << firstCourse;
    cout << "\n";
    cout<< "Modifying the number of students to 6. \n";
    firstCourse.setNumberOfStudents(6);
    cout<< "The number of students now is: " << firstCourse.getNumberOfStudents()<< endl;
    cout << "\n";

    CCourse secondCourse ("11060", "CHEM100F", 3, 2);
    cout<< "The initial information of the second Course: \n";
    cout << secondCourse;
    cout << "\n";
    cout<< "Modifying the number of students to 4. \n";
    secondCourse.setNumberOfStudents(4);
    cout<< "The modified number of students: " << secondCourse.getNumberOfStudents()<< endl;
    cout <<"\n";
    cout<< "The updated information of the second Course: \n";
    cout << secondCourse;
    cout << "\n";

    //Your code HERE to test the class CStudentInfo

    CStudentInfo firstStudent;
    cout<< "The default information of the first Course: \n";
    cout << firstStudent;
    cout << "\n";
    cout << "(First Name, Middle initial, Last Name, Units, Term(as int)" << endl
         << "Please enter the information for the student: ";
    cin >> firstStudent;
    cout << "\n";
    cout<< "The inputted information of the first student: \n";
    cout << firstStudent;
    cout << "\n";
    cout<< "Modifying Term of the student to be Sophomore. \n";
    firstStudent.setTerm(2);
    cout<< "The term of the student now is: " << firstStudent.termToString() << endl;
    cout << "\n";

    CStudentInfo secondStudent ("Z270", "Julio", 'E', "Sandino", 15, 1);
    cout<< "The initial information of the second student: \n";
    cout << secondStudent;
    cout << "\n";
    cout<< "Modifying the term to Senior. \n";
    secondStudent.setTerm(4);
    cout<< "The term of the student now is: " << secondStudent.termToString() << endl;
    cout <<"\n";
    cout<< "The updated information of the second Course: \n";
    cout << secondStudent;
}