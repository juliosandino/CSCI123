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
#include "CDepartment.h"
#include "CCourse.h"
#include <string>
using namespace std;

const int COURSE_LIST_SIZE = 40;
const int STUDENT_LIST_SIZE = 10;
const int DEPARTMENT_LIST_SIZE = 10;
CStudentInfo students[STUDENT_LIST_SIZE];
CCourse courses[COURSE_LIST_SIZE];
CDepartment departments[DEPARTMENT_LIST_SIZE];
bool courseSucceed = false;
bool studentSucceed = false;
bool departmentSucceed = false;

const char courseFilePath[] = "Courses.dat";
const char studentFilePath[] = "Students.dat";
const char departmentFilePath[] = "Departments.dat";

int menu ();
void listAllDepartments();
void addDepartment();
bool doesDepartmentExist(string ID);
void listAllCourses ();
void addCourse();
bool doesCourseExist(string CRN);
void cancelCourse();
void listCoursesOfSpecificDepartment ();
void listCoursesWithLessSpecificUnit ();
void listCoursesWithEqualSpecificUnit ();
void listCoursesWithMoreSpecificUnit ();
void listCoursesWithSpecificTitle ();
void listCourseInfoWithSpecificCrn ();
void listAllStudentsInCourse ();
void listAllStudentInfoWithSpecificTerm ();
void listAllStudentInfoWithSpecificLastName ();
void listStudentInfoWithSpecificId ();
void Enroll ();
bool isCoursesArrayOpen(CStudentInfo student);
void Quit();
void listAllStudents();
CStudentInfo studentByID(string ID);

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

//Function to read department info
void readDepartmentInfo();
//Function to write department info
void writeDepartmentInfo();

int main()
{
// Read Student information from the file Students.dat
    readStudentInfo();

// Read course information from the file Courses.dat
    readCourseInfo();

//Read department info
	readDepartmentInfo();

    if (courseSucceed && studentSucceed && departmentSucceed) {
        int choice;
        do {
            //system("clear");
            choice = menu();

            switch (choice) {
                case 1:
                    listAllDepartments();
                    break;
                case 2:
					addDepartment();
                    break;
                case 3:
					listAllCourses();
                    break;
                case 4:
					addCourse();
                    break;
                case 5:
					cancelCourse();
                    break;
                case 6:
					listCoursesOfSpecificDepartment();
                    break;
                case 7:
					listCoursesWithLessSpecificUnit();
                    break;
                case 8:
                    listCoursesWithEqualSpecificUnit();
                    break;
				case 9:
					listCoursesWithMoreSpecificUnit();
					break;
                case 10:
                    listCourseInfoWithSpecificCrn();
                    break;
                case 11:
                    listCoursesWithSpecificTitle();
                    break;
                case 12:
                    listAllStudentsInCourse();
                    break;
                case 13:
                    listAllStudentInfoWithSpecificTerm();
                    break;
                case 14:
                    listAllStudentInfoWithSpecificLastName();
                    break;
				case 15:
					listStudentInfoWithSpecificId();
					break;
				case 16:
					Enroll();
					break;
				case 17:
					Quit();
					break;
                default:
                    cout << "That was an invalid choice, please try again! \n";
            }
			cin.get();
		} while (choice > 0 && choice < 17);
    } else {
        cout << "File not found!" << endl;
    }

    return 0;
}

int menu ()
{
    int option;
    cout<< "             COLLEGE ENROLLMENT SYSTEM \n\n";
    cout<< "1.  List all department \n";
    cout<< "2.  Add a department \n";
    cout<< "3.  List all courses \n";
    cout<< "4.  Add a Course \n";
    cout<< "5.  Cancel a course  \n";
    cout<< "6.  List all courses of a specific department \n";
    cout<< "7.  List all courses with a number of units less than a specific number \n"; 
    cout<< "8.  List all courses with a specific number of units \n";
    cout<< "9.  List All courses with number of units greater than a specific number \n";
    cout<< "10. List information of a specific course title using the CRN \n";
    cout<< "11. list all CRN of courses with specific title \n";
    cout<< "12. List information of all students enrolled in a specific course \n";
    cout<< "13. List information of all students with a specific term \n";
    cout<< "14. List information of all students with a specific last name \n";
    cout<< "15. List information of a specific student using his/her ID \n";
    cout<< "16. Enroll into a class \n";
    cout<< "17. Quit \n\n";

    cout<< "Please select your option: ";
    cin>> option;
    while (option < 1 || option > 17)
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

    cout << endl;
}

void listAllDepartments(){
	for (int i = 0; i< DEPARTMENT_LIST_SIZE; i++) {
		if (departments[i].exists()){
			cout << departments[i] << endl;
		}
	}

    cout << endl;
}

void listCoursesOfSpecificDepartment ()
{
    int choice;
    int counter = 0;
    bool valid = true;
    CDepartment department;
    int courseCounter = 0;

    for (int i = 0; i < DEPARTMENT_LIST_SIZE; i++){
        if (departments[i].exists()) {
            cout << "[" << i + 1 << "] " <<  departments[i] << endl;
            counter++;
        }
    }

    while(valid) {
        cin >> choice;

        if (choice < 1 || choice > counter) {
            cout << "invalid choice" << endl;
            continue;
        }

        valid = false;
    }

    department = departments[choice - 1];

    for (int i = 0; i < COURSE_LIST_SIZE; i++){
        if (!courses[i].Title.find(department.ID)) {
            cout << courses[i] << endl;
            courseCounter++;
        }
    }

    if (!courseCounter) {
        cout << "No courses in that department!" << endl << endl;
    }
}

void listCoursesWithLessSpecificUnit ()
{
    int units;
    int numberPrinted = 0;
    cout<< "Please enter a number of Units: ";
    cin >> units;

    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
        if (courses[i].exists()) {
            if (courses[i].units < units) {
                cout << courses[i];
                numberPrinted++;
            }
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
        if (courses[i].exists()) {
            if (courses[i].units == units) {
                cout << courses[i];
                numberPrinted++;
            }
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
        if (courses[i].exists()) {
            if (courses[i].units > units) {
                cout << courses[i];
                numberPrinted++;
            }
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

void listAllStudentInfoWithSpecificTerm () {
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

    cout << endl;
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

    cout << endl;
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

    cout << endl;
}

void Enroll ()
{
    bool coursesArrayFull = false;
    bool alreadyEnrolled = false;
    CStudentInfo* student;
    int choice;
    string ID;
    cout << "Would you like to use your ID or name to enroll?" << endl;
    cout << "[1] " << "ID" << endl;
    cout << "[2] " << "Name" << endl;
    cin >> choice;
    while (choice < 1 || choice > 2) {
        cout << "invalid choice! please enter 1 or 2: ";
        cin >> choice;
    }
    if (choice == 1) {
        cout << "Please enter your ID: ";
        cin >> ID;
    } else if (choice == 2) {
        string lastName;
        string firstName;
        cout << "Please enter your first name and last name: ";
        cin >> firstName >> lastName;
        ID = searchId(firstName, lastName);
    }

    if (ID == "Not found!") {
        cout << "Error! Student not found!" << endl;
        return;
    }

    int courseArrayPlace;
    int studentArrayPlace;

    int counter = 0;

    for (int i = 0; i < STUDENT_LIST_SIZE; i++) {
        if (students[i].ID == ID) {
            if (isCoursesArrayOpen(students[i])) {
                student = &students[i];
                studentArrayPlace = i;
            } else {
                cout << "Enrollment cancelled! You are enrolled in the maximum amount of classes allowed" << endl;
                coursesArrayFull = true;
            }
            counter++;
        }
    }

    if (counter == 0){
        cout << "ID not found!" << "\n\n";
    } else if (!coursesArrayFull) {
        string crn;
        CCourse *course;
        int courseFoundCounter = 0;

        cout << endl << "Please enter the department of the class that you wish to enroll into" << endl << endl;
        listCoursesOfSpecificDepartment();

        cout << "Please enter the CRN of the class you want to Join> ";
        cin >> crn;
        for (int i = 0; i < COURSE_LIST_SIZE; i++) {
            if (courses[i].CRN == crn) {
                course = &courses[i];
                courseArrayPlace = i;
                courseFoundCounter++;
            }
        }

        for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
            if (student->ID == course->students[i]) {
                alreadyEnrolled = true;
            }
        }

        if (courseFoundCounter == 0) {
            cout << "No class has a CRN of \"" << crn << "\"\n\n";
        } else if (alreadyEnrolled) {
            cout << "Error! You're already enrolled in that class!" << "\n\n";
        }
        else if (student->units + course->units > 12){
            cout << "Error! You would be enrolling in more units than allowed." << endl;
        } else {
            char answer;
            cout << "Are you sure you want to enroll in: " << course->Title << "(Y/N)";
            cin >> answer;

            if (toupper(answer) == 'Y') {
                student->units += course->units;
                courses[courseArrayPlace].setNumberOfStudents(courses[courseArrayPlace].getNumberOfStudents() + 1);

                for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
                    if (courses[courseArrayPlace].students[i] == "N/A"){
                        courses[courseArrayPlace].students[i] = student->ID;
                        break;
                    }
                }

                for (int i = 0; i < NUMBER_OF_COURSES; i++) {
                    if (students[studentArrayPlace].classes[i] == "N/A"){
                        students[studentArrayPlace].classes[i] = course->CRN;
                        break;
                    }
                }

                cout << endl << "You've succesfully enrolled in " << course->Title << "!" << endl << endl;
            }
        }
    }

}

void Quit() {
// Write Student information back to the file Students.dat
    writeStudentInfo();
// Write Course information back to the file Courses.dat
    writeCourseInfo();
// Write Department information back to the file departments.dat
	writeDepartmentInfo();
    cout<< "Have a nice day \n\n";
}

void readDepartmentInfo(){
	ifstream departmentFile;

	departmentFile.open(departmentFilePath);

	if (departmentFile.fail()){
		cout << "Department File not found!" << endl;
	} else {
		departmentSucceed = true;
		for (int i = 0; i < DEPARTMENT_LIST_SIZE; i++) {
			departmentFile >> departments[i];
		}
	}
}

void readStudentInfo() {
    ifstream studentFile;

    //fix the path at the end man
    studentFile.open(studentFilePath);

    if (studentFile.fail()) {
        cout << "Student File not found!" << endl;
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
    courseFile.open(courseFilePath);

    if (courseFile.fail()) {
        cout << "Courses File not found!" << endl;
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

    studentFile.open(studentFilePath);

    if (studentFile.fail()) {
        cout << "Error Student file not found!" << endl;
    } else {
        for (int i = 0; i < STUDENT_LIST_SIZE; i++) {
			if (students[i].exists()) {
				studentFile << students[i] << "\n";
			}
        }
    }

    studentFile.close();
}

void writeCourseInfo() {
    ofstream coursesFile;

    coursesFile.open(courseFilePath);

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

void writeDepartmentInfo(){
	ofstream departmentFile;

	departmentFile.open(departmentFilePath);

	if (departmentFile.fail()){
		cout << "Error Department file not found!" << endl;
	} else {
		for (int i = 0; i < DEPARTMENT_LIST_SIZE; i++) {
			if (departments[i].exists()) {
				departmentFile << departments[i] << endl;
			}
		}
	}

	departmentFile.close();
}

int getEnrolledUnits(string studentId) {
    for (int i = 0; i < STUDENT_LIST_SIZE; i++) {
        if (students[i].ID == studentId){
            return students[i].units;
        }
    }

	return 999;
}

string searchId(string first, string last) {
    for (int i = 0; i < STUDENT_LIST_SIZE; i++){
        if (students[i].firstName == first && students[i].lastName == last){
            return students[i].ID;
        }
    }

	return "Not found!";
}

void addDepartment() {
    bool spaceOpen = false;
    string defaultID = "Z000";
    CDepartment* department;
    string ID, Name;

    for (int i = 0; i < DEPARTMENT_LIST_SIZE; i++) {
        if (departments[i].ID == defaultID){
            department = &departments[i];
            spaceOpen = true;
            break;
        }
    }

    if (spaceOpen) {
        do {
        cout << "(ID, Name)" << endl;
        cout << "ID must be at most 4 letters long and Name must be one word" << endl;
        cout << "Please enter Department ID and name: ";
        cin >> ID >> Name;
            if (doesDepartmentExist(ID)){
                cout << "Error! \"" << ID << "\" department ID already exists! Please use another" << endl;
                cout << "To cancel enter \"q\" as department ID" << endl << endl;
            }
        } while (doesDepartmentExist(ID));

        if (ID == "q") {
            cout << "Department addition was cancelled!" << endl;
            return;
        } else {
            department->ID = ID;
            department->Name = Name;
            cout << "Addition Succesful! New Department is: " << *department << "\n\n";
        }
    } else {
        cout << "There is no open space to create a new department!!" << endl << endl;
    }
}

void addCourse() {
    bool spaceOpen = false;
    string defaultCRN = "Z000";
    CCourse* course;
    string CRN, Title;
    int Units;

    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
        if (courses[i].CRN == defaultCRN) {
            spaceOpen = true;
            course = &courses[i];
        }
    }

    if (spaceOpen) {
        do {
            cout << "(CRN, Title, Units)" << endl;
            cout << "CRN must be most 5 digits long and Name must be one word" << endl;
            cout << "Please enter Department ID Title and Units: ";
            cin >> CRN >> Title >> Units;

            if (doesCourseExist(CRN)){
                cout << "Error! \"" << CRN << "\" course CRN already exists! Please use another" << endl;
                cout << "To cancel enter \"q\" as course CRN" << endl << endl;
            }
        } while (doesCourseExist(CRN));

        if (CRN == "q") {
            cout << "Course addition cancelled!";
            return;
        } else {
            course->CRN = CRN;
            course->Title = Title;
            course->units = Units;
            cout << "Addition Succesful! The new course is:" << endl;
            cout << *course;
        }
    } else {
        cout << "There is no open space for a new course!";
    }

}

void cancelCourse() {
    string crn;
    char answer;
    int studentCounter = 0;
    int courseArrayPlace;

    try {
        cout << "Please enter the CRN of the class you wish to cancel?" << endl;
        cin >> crn;
        bool found = false;

        for (int i = 0; i < COURSE_LIST_SIZE; i++) {
            if (courses[i].CRN == crn) {
                courseArrayPlace = i;
                found = true;
                break;
            }
        }

        if (!found) {
            throw crn;
        }

        do {
            cout << "are you sure you wish to cancel class: " << "\n" << courses[courseArrayPlace] << " (Y/N): ";
            cin >> answer;

            if (toupper(answer) != 'Y' && toupper(answer) != 'N') {
                cout << "invalid answer" << endl;
            }
        } while (toupper(answer) != 'Y' && toupper(answer) != 'N');

        if (toupper(answer) == 'Y') {

            cout << "Students to be unenrolled from the class: " << endl;

            for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
                for (int j = 0; j < STUDENT_LIST_SIZE; j++) {
                    if (students[j].ID == courses[courseArrayPlace].students[i]) {
                        for (int k = 0; k < NUMBER_OF_COURSES; k++) {
                            if (students[j].classes[k] == courses[courseArrayPlace].CRN) {
                                cout << students[j] << endl;
                                students[j].classes[k] = "N/A";
                                studentCounter++;
                                students[j].units -= courses[courseArrayPlace].units;
                                courses[courseArrayPlace].students[i] = "N/A";
                            }
                        }
                    }
                }
            }

            courses[courseArrayPlace].CRN = "Z000";

            if (studentCounter == 0) {
                cout << "There were no students enrolled in the course" << endl;
            }

            cout << "\n" << "The following class was Cancelled!" << endl;
        }
    } catch (string e) {
        cout << "Error! " << e << " CRN was not found!" << endl;
    }

}

void listAllStudentsInCourse() {
    string crn;
    int courseCounter = 0;
    CCourse course;
    cout << "Please enter the CRN of the course > ";
    cin >> crn;

    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
        if (courses[i].CRN == crn) {
            course = courses[i];
            courseCounter++;
            break;
        }
    }

    if (courseCounter) {
        int studentCounter = 0;
        for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
            if (course.students[i] != "N/A") {
                CStudentInfo student = studentByID(course.students[i]);
                cout << student << endl;
                studentCounter++;
            }
        }

        if (studentCounter == 0) {
            cout << "There are no students enrolled in that class!" << endl;
        }
    } else {
        cout << "Error! No Class with that CRN!" << endl << endl;
    }

    cout << endl;
}

bool doesCourseExist(string CRN) {
    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
        if (courses[i].CRN == CRN) {
            return true;
        }
    }
    return false;
}

bool doesDepartmentExist(string ID) {
    for (int i = 0; i < DEPARTMENT_LIST_SIZE; i++) {
        if (departments[i].ID == ID) {
            return true;
        }
    }
    return false;
}

bool isCoursesArrayOpen(CStudentInfo student){
    //Number of courses is the size of the array
    //of courses every CStudentInfo object has
    //for this project default is 5
    for (int i = 0; i < 5; i++) {
        if (student.classes[i] == "") {
            return true;
        }
    }
    return false;
}

CStudentInfo studentByID(string ID) {
    for (int i = 0; i < STUDENT_LIST_SIZE; i++) {
        if (students[i].ID == ID) {
            return students[i];
        }
    }
    return CStudentInfo();
}
