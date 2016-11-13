//main.cpp
//Programmer: Julio Sandino                                             CSCI 123, Fall 2016
//Project 4                                                             Instructor: Mai, Timothy
//Due Date: 11/0STUDENT_LIST_SIZE/16                                                    Date Submitted: 11/0STUDENT_LIST_SIZE/16

//Program Description:
//This program will be able to log student info and course info in a college enrollment system
//it will read from a file and output to that file
//it will employ multiple classes, and will be interactive with the user.
//It will work just as any other enrollment system would work

#include <iostream>
#include <fstream>
#include "CStudentInfo.h"
#include "CCourse.h"
#include <string>
using namespace std;

const int COURSE_LIST_SIZE = 40;
const int STUDENT_LIST_SIZE = 10;
CStudentInfo students[STUDENT_LIST_SIZE];
CCourse courses[COURSE_LIST_SIZE];
bool courseSucceed = false;
bool studentSucceed = false;

const string courseFilePath = "Courses.dat";
const string studentFilePath = "Students.dat";

int menu ();
void listAllCourses ();
void listCoursesOfSpecificDepartment ();
void listCoursesWithLessSpecificUnit ();
void listCoursesWithEqualSpecificUnit ();
void listCoursesWithMoreSpecificUnit ();
void listCoursesWithSpecificTitle ();
void listCourseInfoWithSpecificCrn ();
void listAllStudents ();
void listAllStudentInfoWithSpecificTerm ();
void listAllStudentInfoWithSpecificLastName ();
void listStudentInfoWithSpecificId ();
void Enroll ();
void Quit();

string searchId(string first, string last);
int getEnrolledUnits(string studentId);

// Function to read Student information from the file Students.dat
void readStudentInfo();
// Function to write Student information back to the file Students.dat
void writeStudentInfo();

// Function to read course information from the file Courses.dat
void readCourseInfo();
// Function to write course information back to the file Courses.dat
void writeCourseInfo();

int main()
{

// Read Student information from the file Students.dat
    readStudentInfo();

// Read course information from the file Courses.dat
    readCourseInfo();

    if (courseSucceed && studentSucceed) {
        int choice;
        do {
            //system("clear");
            choice = menu();

            switch (choice) {
                case 1:
                    listAllCourses();
                    break;
                case 2:
                    listCoursesOfSpecificDepartment();
                    break;
                case 3:
                    listCoursesWithLessSpecificUnit();
                    break;
                case 4:
                    listCoursesWithEqualSpecificUnit();
                    break;
                case 5:
                    listCoursesWithMoreSpecificUnit();
                    break;
                case 6:
                    listCoursesWithSpecificTitle();
                    break;
                case 7:
                    listCourseInfoWithSpecificCrn();
                    break;
                case 8:
                    listAllStudents();
                    break;
                case 9:
                    listAllStudentInfoWithSpecificTerm();
                    break;
                case 10:
                    listAllStudentInfoWithSpecificLastName();
                    break;
                case 11:
                    listStudentInfoWithSpecificId();
                    break;
                case 12:
                    Enroll();
                    break;
                case 13:
                    Quit();
                    break;
                default:
                    cout << "That was an invalid choice, please try again! \n";
            }
			cin.get();
		} while (choice > 0 && choice < 13);
    } else {
        cout << "File not found!";
    }

    return 0;
}

int menu ()
{
    int option;
    cout<< "             COLLEGE ENROLLMENT SYSTEM \n\n";
    cout<< "1.  List All Courses. \n";
    cout<< "2.  List All Courses Of A Specific Department. \n";
    cout<< "3.  List All Courses With Number Of Units Less Than A Specific Number. \n";
    cout<< "4.  List All Courses With A Specific Number Of Units. \n";
    cout<< "5.  List All Courses With Number Of Units More Than A Specific Number. \n";
    cout<< "6.  List All Courses With A Specific Title. \n";
    cout<< "7.  List Course Information With CRN. \n";
    cout<< "8.  List All Students.\n";
    cout<< "9.  List All Students With A Specific Year Term. \n";
    cout<< "10. List All Students With A Specific Last Name. \n";
    cout<< "11. List Student Information With ID. \n";
    cout<< "12. Enroll Into A Course. \n";
    cout<< "13. Quit. \n\n";

    cout<< "Please select your option: ";
    cin>> option;
    while (option < 1 || option > 13)
    {
        cout<< "Invalid option!!! Please select valid option: ";
        cin>> option;
    }
    return option;
}

void listAllCourses ()
{
    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
		if (courses[i].exists()){
			cout << courses[i];
		}
    }
}
void listCoursesOfSpecificDepartment ()
{
    int choice;
    bool valid = true;
    cout << "[1] MATHEMATICS " << endl;
    cout << "[2] SCIENCE" << endl;
    cout << "[3] ENGLISH" << endl;
    cout << "[4] HISTORY" << endl;
    cout << "[5] COMPUTER SCIENCE" << endl;

    while(valid) {
        cin >> choice;

        if (choice > 5 || choice < 1) {
            cout << "invalid choice" << endl;
            continue;
        }

        valid = false;
    }

    switch (choice){
        case 1:
            for(int i = 0; i < COURSE_LIST_SIZE; i++)
                if (courses[i].Title.find("MATH") != string::npos)
                    cout << courses[i];
            break;

        case 2:
            for(int i = 0; i < COURSE_LIST_SIZE; i++)
                if (courses[i].Title.find("CHEM") != string::npos)
                    cout << courses[i];
            break;

        case 3:
            for(int i = 0; i < COURSE_LIST_SIZE; i++)
                if (courses[i].Title.find("ENGL") != string::npos)
                    cout << courses[i];
            break;

        case 4:
            for(int i = 0; i < COURSE_LIST_SIZE; i++)
                if (courses[i].Title.find("HIST") != string::npos)
                    cout << courses[i];
            break;

        case 5:
            for(int i = 0; i < COURSE_LIST_SIZE; i++)
                if (courses[i].Title.find("CSCI") != string::npos)
                    cout << courses[i];
            break;
        default:
            cout << "ERROR" << endl;
    }
}

void listCoursesWithLessSpecificUnit ()
{
    int units;
    int numberPrinted = 0;
    cout<< "Please enter a number of Units: ";
    cin >> units;

    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
        if (courses[i].units < units) {
            cout << courses[i];
            numberPrinted++;
        }
    }

    if(numberPrinted == 0) {
        cout << "No class had units fewer than " << units << " units" << endl;
    }
}

void listCoursesWithEqualSpecificUnit ()
{
    int units;
    int numberPrinted = 0;
    cout<< "Please enter a number of Units: ";
    cin >> units;

    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
        if (courses[i].units == units) {
            cout << courses[i];
            numberPrinted++;
        }
    }

    if(numberPrinted == 0) {
        cout << "No class had " << units << " units" << endl;
    }
}

void listCoursesWithMoreSpecificUnit ()
{
    int units;
    int numberPrinted = 0;
    cout<< "Please enter a number of Units: ";
    cin >> units;

    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
        if (courses[i].units > units) {
            cout << courses[i];
            numberPrinted++;
        }
    }

    if(numberPrinted == 0) {
        cout << "No class had more than " << units << " units" << endl;
    }
}

void listCoursesWithSpecificTitle ()
{
    string title;
    int numberPrinted = 0;
    cout<< "Please Type the name of the class: ";
    cin >> title;

    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
        if (courses[i].Title.compare(title) == 0) {
            cout << courses[i];
            numberPrinted++;
        }
    }

    if(numberPrinted == 0) {
        cout << "No class named " << title << endl;
    }
}

void listCourseInfoWithSpecificCrn ()
{
    string CRN;
    int numberPrinted = 0;
    cout<< "Please enter the CRN: ";
    cin >> CRN;

    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
        if (courses[i].CRN == CRN) {
            cout << courses[i];
            numberPrinted++;
        }
    }

    if(numberPrinted == 0) {
        cout << "No class had a CRN of " << CRN << endl;
    }
}

void listAllStudents ()
{
    for (int i = 0; i < STUDENT_LIST_SIZE; i++) {
		if (students[i].exists()){
			cout << students[i] << endl;
		}
    }
}

void listAllStudentInfoWithSpecificTerm ()
{
    YearTerm temp;
    int term;
    cout << "Please enter the yearterm as int(if unknown enter 0)> ";
    cin >> term;

    int counter = 0;

    switch (term){
        case 1:
            temp = FRESHMAN;
            break;
        case 2:
            temp = SOPHOMORE;
            break;
        case 3:
            temp = JUNIOR;
            break;
        case 4:
            temp = SENIOR;
            break;
        default:
            temp = UNKNOWN;
    }

    for (int i = 0; i < STUDENT_LIST_SIZE; i++) {
        if (students[i].getTerm() == temp) {
            cout << students[i] << endl;
            counter++;
        }
    }

    if (counter == 0){
        cout << "There were no students with that term" << endl;
    }
}

void listAllStudentInfoWithSpecificLastName ()
{
    string temp;
    cout << "Enter the student's Lastname> ";
    cin >> temp;

    int counter = 0;

    for (int i = 0; i < STUDENT_LIST_SIZE; i++) {
        if (students[i].lastName == temp){
            cout << students[i] << endl;
            counter++;
        }
    }

    if (counter == 0) {
        cout << "There were no students with the the last name: " << temp << endl;
    }
}

void listStudentInfoWithSpecificId ()
{
    string temp;
    cout << "Enter the student's ID: ";
    cin >> temp;

    int counter = 0;

    for (int i = 0; i < STUDENT_LIST_SIZE; i++) {
        if (students[i].ID == temp){
            cout << students[i] << endl;
            counter++;
			break;
        }
    }

    if (counter == 0) {
        cout << "There were no students with the ID: " << temp << endl;
    }
}

void Enroll ()
{
    CStudentInfo student;
    string ID;
    cout << "Please enter your ID> ";
    cin >> ID;
    int studentArrayPlace;
    int courseArrayPlace;

    int counter = 0;

    for (int i = 0; i < STUDENT_LIST_SIZE; i++) {
        if (students[i].ID == ID) {
            student = students[i];
            studentArrayPlace = i;
            counter++;
            break;
        }
    }

    if (counter == 0){
        cout << "ID not found!" << "\n\n";
    } else {
        string crn;
        CCourse course;
        listCoursesOfSpecificDepartment();

        cout << "Please enter the CRN of the class you want to Join> ";
        cin >> crn;
        for (int i = 0; i < COURSE_LIST_SIZE; i++) {
            if (courses[i].CRN == crn) {
                course = courses[i];
                courseArrayPlace = i;
                break;
            }
        }

        if (student.units + course.units > 12){
            cout << "Error! You would be enrolling in more units than allowed." << endl;
        } else {
            char answer;
            cout << "Are you sure you want to enroll in: " << course.Title << "(Y/N)";
            cin >> answer;

            if (toupper(answer) == 'Y') {
                students[studentArrayPlace].units += courses[courseArrayPlace].units;
                courses[courseArrayPlace].setNumberOfStudents(courses[courseArrayPlace].getNumberOfStudents() + 1);

                cout << "You've succesfully enrolled in " << course.Title << "!" << endl;
            }
        }
    }

}

void Quit()
{
// Write Student information back to the file Students.dat
    writeStudentInfo();
// Write Course information back to the file Courses.dat
    writeCourseInfo();

    cout<< "Have a nice day \n\n";
}

void readStudentInfo() {
    ifstream studentFile;

    //fix the path at the end man
    studentFile.open("Students.dat");

    if (studentFile.fail()) {
        cout << "File not found!";
    } else {
        studentSucceed = true;
        for (int i = 0; i < STUDENT_LIST_SIZE; i++) {
            studentFile >> students[i];
        }
    }

    studentFile.close();
}

void readCourseInfo() {
    ifstream courseFile;

    //fix the path at the end man
    courseFile.open("Courses.dat");

    if (courseFile.fail()) {
        cout << "File not found!";
    } else {
        courseSucceed = true;
        for (int i = 0; i < COURSE_LIST_SIZE; i++) {
            courseFile >> courses[i];
        }
    }

    courseFile.close();
}

void writeStudentInfo() {
    ofstream studentFile;

    studentFile.open("Students.dat");

    if (studentFile.fail()) {
        cout << "Error Student file not found!" << endl;
    } else {
        for (int i = 0; i < STUDENT_LIST_SIZE; i++) {
			if (students[i].exists() {
				studentFile << students[i] << "\n";
			}
        }
    }

    studentFile.close();
}

void writeCourseInfo() {
    ofstream coursesFile;

    coursesFile.open("Courses.dat");

    if (coursesFile.fail()) {
        cout << "Error Course file not found!" << endl;
    } else {
        for (int i = 0; i < COURSE_LIST_SIZE; i++) {
			if (courses[i].exists()) {
				coursesFile << courses[i];
			}
        }
    }

    coursesFile.close();
}

int getEnrolledUnits(string studentId) {
    for (int i = 0; i < STUDENT_LIST_SIZE; i++) {
        if (students[i].ID == studentId){
            return students[i].units;
        }
    }
}

string searchId(string first, string last) {
    for (int i = 0; i < STUDENT_LIST_SIZE; i++){
        if (students[i].firstName == first && students[i].lastName == last){
            return students[i].ID;
        }
    }
}
