#include <iostream>
#include "CStudentInfo.h"
#include "CCourse.h"
using namespace std;

int main() {
    CCourse firstCourse;
    cout<< "The default information of the first Course: \n";
    firstCourse.showInfo();
    cout << "\n";
    firstCourse.getInfo();
    cout << "\n";
    cout<< "The inputted information of the first Course: \n";
    firstCourse.showInfo();
    cout << "\n";
    cout<< "Modifying the number of students to 6. \n";
    firstCourse.setNumberOfStudents(6);
    cout<< "The number of students now is: " << firstCourse.getNumberOfStudents()<< endl;
    cout << "\n";

    CCourse secondCourse ("11060", "CHEM100F", 3, 2);
    cout<< "The initial information of the second Course: \n";
    secondCourse.showInfo();
    cout << "\n";
    cout<< "Modifying the number of students to 4. \n";
    secondCourse.setNumberOfStudents(4);
    cout<< "The modified number of students: " << secondCourse.getNumberOfStudents()<< endl;
    cout <<"\n";
    cout<< "The updated information of the second Course: \n";
    secondCourse.showInfo();
    cout << "\n";

    //Your code HERE to test the class CStudentInfo

    CStudentInfo firstStudent;
    cout<< "The default information of the first Course: \n";
    firstStudent.showInfo();
    cout << "\n";
    firstStudent.getInfo();
    cout << "\n";
    cout<< "The inputted information of the first Course: \n";
    firstStudent.showInfo();
    cout << "\n";
    cout<< "Modifying Term of the student to be Sophomore. \n";
    firstStudent.setTerm(2);
    cout<< "The term of the student now is: " << firstStudent.getTerm() << endl;
    cout << "\n";

    CStudentInfo secondStudent ("Z270", "Julio", 'E', "Sandino", 15, 1);
    cout<< "The initial information of the second student: \n";
    secondStudent.showInfo();
    cout << "\n";
    cout<< "Modifying the term to Senior. \n";
    secondStudent.setTerm(4);
    cout<< "The term of the student now is: " << secondStudent.getTerm()<< endl;
    cout <<"\n";
    cout<< "The updated information of the second Course: \n";
    secondStudent.showInfo();
}