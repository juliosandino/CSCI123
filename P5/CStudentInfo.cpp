//
// Created by Julio Sandino on 11/6/16.
//

#include "CStudentInfo.h"

//Destructor
CStudentInfo::~CStudentInfo() {}

//Constructors here
CStudentInfo::CStudentInfo(){
    ID = "Z9999";
    firstName = "None";
    middleInitial = '?';
    lastName = "None";
    units = 0;
    Term = UNKNOWN;
	for (int i = 0; i < 5; i++) {
		classes[i] = "N/A";
	}
}

//parameterized constructor
CStudentInfo::CStudentInfo(string ID, string firstName, char middleInitial, string lastName, int units, int term) {
    this->ID = ID;
    this->firstName = firstName;
    this->middleInitial = middleInitial;
    this->lastName = lastName;
    this->units = units;

    //switch statment is needed to change int to YearTerm
    switch (term){
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
    }

	for (int i = 0; i < 5; i++) {
		classes[i] = "N/A";
	}	
}

//copy constructor
CStudentInfo::CStudentInfo(const CStudentInfo &student) {
    this->ID = student.ID;
    this->firstName = student.firstName;
    this->middleInitial = student.middleInitial;
    this->lastName = student.lastName;
    this->units = student.units;
    this->Term = student.Term;
}

//accesor method
YearTerm CStudentInfo::getTerm() {
    return Term;
}

//Mutator method
void CStudentInfo::setTerm(int term) {
    //switch statement needed to turn int to YearTerm
    switch (term){
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
    }
}

//to string method
string CStudentInfo::termToString() {
    //switch needed to turn YearTerm to String

    switch (Term){
        case UNKNOWN:
            return "Unknown";
        case FRESHMAN:
            return "Freshman";
        case SOPHOMORE:
            return "Sophomore";
        case JUNIOR:
            return "Junior";
        case SENIOR:
            return "Senior";
        default:
            return "ERROR!";
    }
}

//operator overloading
istream&operator >> (istream &ins, CStudentInfo &student) {
    string tempString;
    ins >> student.ID >> student.firstName >> student.middleInitial >> student.lastName >> student.units >> tempString;

	for (int i = 0; i < 5; i++){
		ins >> student.classes[i];
	}

    if (tempString == "Freshman") {
        student.setTerm(1);
    } else if (tempString == "Sophomore") {
        student.setTerm(2);
    } else if (tempString == "Junior") {
        student.setTerm(3);
    } else if (tempString == "Senior") {
        student.setTerm(4);
    } else {
        student.setTerm(0);
    }

    return ins;
}

ostream&operator << (ostream &outs, CStudentInfo &student) {
    outs << student.ID << "\t" << student.firstName << "\t" << student.middleInitial << "\t" << student.lastName << "\t\t";
    outs << student.units << "\t" << student.termToString() << "\t\t";
	
	for (int i = 0; i < 5; i++) {
		outs << student.classes[i] << "\t";
	}

    return outs;
}
