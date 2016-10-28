//P3.cpp
//Programmer: Julio Sandino                                             CSCI 123, Fall 2016
//Project 3                                                             Instructor: Mai, Timothy
//Due Date: 10/27/16                                                    Date Submitted: 10/27/16

//Program Description:

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct SCourse
{
    int CRN;
    string Title;
    int Units;
    int NumberOfStudents;
};

const string fileName = "Courses.dat";
ifstream inFile;
ofstream outFile;
bool fileIsOpen = true;

int menu ();
void listAllCourses ();
void listCoursesOfSpecificDepartment ();
void listCoursesWithLessSpecificUnit ();
void listCoursesWithEqualSpecificUnit ();
void listCoursesWithMoreSpecificUnit ();
void listCoursesWithSpecificTitle ();
void listCourseInfoWithSpecificCrn ();
void printClass(int i);
void Enroll ();
void Quit();

const int COURSE_LIST_SIZE = 30;

SCourse courses[COURSE_LIST_SIZE];
// Function to read course information from the file Courses.dat
void readCourseInfo();
// Function to write course information back to the file Courses.dat
void writeCourseInfo();

int main() {

// Read course information from the file Courses.dat
readCourseInfo();

    if (fileIsOpen){
        int choice;
        do {
            system("CLS");

            choice = menu();

            switch (choice) {
            case 1:
                 listAllCourses ();
                 break;
            case 2:
                 listCoursesOfSpecificDepartment ();
                 break;
            case 3:
                 listCoursesWithLessSpecificUnit ();
                 break;
            case 4:
                 listCoursesWithEqualSpecificUnit ();
                 break;
            case 5:
                 listCoursesWithMoreSpecificUnit ();
                 break;
            case 6:
                 listCoursesWithSpecificTitle();
                 break;
            case 7:
                 listCourseInfoWithSpecificCrn();
                 break;
            case 8:
                 Enroll ();
                 break;
            case 9:
                 Quit();
                 break;
            default:
                 cout<< "That was an invalid choice, please try again! \n";
            }
			system("PAUSE");
       } while (choice > 0 && choice < 9);
    }

    return 0;
}

int menu () {

       int option;
       cout<< "             COLLEGE ENROLLMENT SYSTEM \n\n";
       cout<< "1.  List All Courses. \n";
       cout<< "2.  List All Courses Of A Specific Department. \n";
       cout<< "3.  List All Courses With Number Of Units Less Than A Specific Number. \n";
       cout<< "4.  List All Courses With A Specific Number Of Units. \n";
       cout<< "5.  List All Courses With Number Of Units More Than A Specific Number. \n";
       cout<< "6.  List All Courses With A Specific Title. \n";
       cout<< "7.  List Course Information With CRN. \n";
       cout<< "8.  Enroll Into A Course. \n";
       cout<< "9.  Quit. \n\n";

       cout<< "Please select your option: ";
       cin>> option;
       while (option < 1 || option > 9) {
              cout<< "Invalid option!!! Please select valid option: ";
              cin>> option;
       }
       return option;
}

void readCourseInfo() {
	string line;
    string::size_type sz;

    int counter = 0;

	inFile.open(fileName);

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            courses[counter].CRN = stoi (line.substr(0, 5), &sz);
            courses[counter].Title = line.substr(9, 9);
            courses[counter].Units = stoi (line.substr(31, 32), &sz);
            courses[counter].NumberOfStudents = stoi (line.substr(line.length() -1), &sz);
            counter++;
        }
    } else {
        cout << "INPUT FILE NOT FOUND!" << endl;
        fileIsOpen = false;
    }

	inFile.close();
}

void writeCourseInfo() {
	outFile.open(fileName);

	for(int i = 0; i < COURSE_LIST_SIZE; i++) {
		outFile	<< courses[i].CRN << "    "
			<< courses[i].Title << "              "
			<< courses[i].Units << "             "
			<< courses[i].NumberOfStudents << endl; 
	}
	outFile.close();
}



void listAllCourses ()
{
    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
        printClass(i);
    }
}

void listCoursesOfSpecificDepartment() {
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
					printClass(i);
			break;
				
		case 2:
			for(int i = 0; i < COURSE_LIST_SIZE; i++)
				if (courses[i].Title.find("CHEM") != string::npos)
					printClass(i);
			break;

		case 3:
			for(int i = 0; i < COURSE_LIST_SIZE; i++)
				if (courses[i].Title.find("ENGL") != string::npos)
					printClass(i);
			break; 

		case 4:
			for(int i = 0; i < COURSE_LIST_SIZE; i++)
				if (courses[i].Title.find("HIST") != string::npos) 
					printClass(i);
			break;

		case 5:
			for(int i = 0; i < COURSE_LIST_SIZE; i++)
				if (courses[i].Title.find("CSCI") != string::npos) 
					printClass(i);
			break;	
		default:
			cout << "ERROR" << endl;
			}
}

void listCoursesWithLessSpecificUnit ()
{ int units;
    int numberPrinted = 0;
    cout<< "Please enter a number of Units: ";
    cin >> units;

    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
        if (courses[i].Units < units) {
            printClass(i);
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
        if (courses[i].Units == units) {
            printClass(i);
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
        if (courses[i].Units > units) {
            printClass(i);
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
        if (courses[i].Title.compare(title) == 1) {
            printClass(i);
            numberPrinted++;
        }
    }

    if(numberPrinted == 0) {
        cout << "No class named " << title << endl;
    }
}

void listCourseInfoWithSpecificCrn ()
{
    int CRN;
    int numberPrinted = 0;
    cout<< "Please enter the CRN: ";
    cin >> CRN;

    for (int i = 0; i < COURSE_LIST_SIZE; i++) {
        if (courses[i].CRN == CRN) {
            printClass(i);
            numberPrinted++;
        }
    }

    if(numberPrinted == 0) {
        cout << "No class had a CRN of " << CRN << endl;
    }
}

void printClass(int i){
    cout << courses[i].CRN << "\t"
         << courses[i].Title << "\t"
         << courses[i].Units << "\t"
         << courses[i].NumberOfStudents<< endl;
}

void Enroll () {

    int CRN;
	int counter = 0;
	string choice;
	
	cout << "Please enter the CRN of the class: ";
	cin >> CRN;

	for (int i = 0; i < COURSE_LIST_SIZE; i++) {
		if (courses[i].CRN == CRN) {
			counter++;
			cout << endl;
			printClass(i);
			cout << "do you wish to enroll in this class? (y/n)";
			cin >> choice;

			if (choice == "y") {
				courses[i].NumberOfStudents += 1;
				cout << "You've succesfully enrolled!" << endl;
			} else {
				cout << "action cancelled!" << endl;
			}
		}
	}

	if (counter == 0)
		cout << "Class CRN not found!" << endl;
}

void Quit() {
	// Write Student information back to the file Courses.dat
	writeCourseInfo();
    cout<< "Have a nice day \n\n";
}
