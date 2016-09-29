//P2.cpp
//Programmer: Julio Sandino                                             CSCI 123, Fall 2016
//Project 2                                                             Instructor: Mai, Timothy
//Due Date: 9/29/16                                                     Date Submitted: 9/29/16

//Program Description: This program is able to convert the units from metric to english and vice versa
//It employs for loops, static methods, and user input, it will also use
//functions and references to be able to achieve its purpose.

#include <iostream>
#include <cmath>

using namespace std;

//constants that we will need for unit conversion
const double metric_to_english_factor = (1 / 0.3048);
const double english_to_metric_factor = 0.3048;
const double feet_to_inches =  12;
const double inches_to_feet = 1 / feet_to_inches;

//error messages that will be displayed if the user input is invalid
const string metricError = "Invalid value! Please enter a value greater than or equal to 0";
const string englishError = "Invalid values! Please input values greater than or equal to 0";
const string choiceError = "Invalid choice! please choose a number between 1 and 3";

//options that the user will have and an array so we can loop them
const string option1 = "Convert length from Metric to English";
const string option2 = "Convert length from English to Metric";
const string option3 = "Quit the Program";
const string option[] = {option1, option2, option3};

bool keepRunning = true;

//declaring the methods that we will use
//this method prints out the menu to the user
void menu(int& choice);

void EnglishToMetric();
void MetricToEnglish();

void inputMetric(double& m);
void inputEnglish(double& f, double& i);

double convertEtoM(int f, double i);
void convertMtoE(int&f, double&i, double m);

void outputEnglish(double m, int f, double i);
void outputMetric(int f, double i, double m);


bool checkIfValid(double value);


int main() {
    while (keepRunning) {
        int choice;

        cout << "\tMenu" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << ".\t" << option[i] << endl;
        }
        cout << "Please enter your choice:  ";
        cin >> choice;

        menu(choice);
    }
}

void menu(int& choice){
    switch (choice){
        case 1:
            MetricToEnglish();
            break;
        case 2:
            EnglishToMetric();
            break;
        case 3:
            cout << "Goodbye!" << "\n\n";
            keepRunning = false;
            break;
        default:
            cout << choiceError << "\n\n";

    }
    cout << endl;
}
bool checkIfValid(double value){
    return value >= 0;
}

void MetricToEnglish(){
    double meters;
    int feet;
    double inches;

    inputMetric(meters);
    convertMtoE(feet, inches, meters);
    outputMetric(feet, inches, meters);
}

void inputMetric(double& m){
    bool valid = false;

    while (!valid) {
        cout << "Enter a number of meters as a double: ";
        cin >> m;

        if (checkIfValid(m))
            valid = true;
        else {
            cout << metricError << "\n";
        }
    }
}

void convertMtoE(int&f, double&i, double m){
    double calculation = m * metric_to_english_factor;
    f = floor (calculation);
    i = round ((calculation - f) * 100 * feet_to_inches) / 100;
}

void outputMetric(int f, double i, double m){
    cout << m << " meters corresponds to " << f << " feet, " << i << " inches" << "\n\n";
}

void EnglishToMetric(){
    double feet;
    double inches;
    double meters;

    inputEnglish(feet, inches);
    meters = convertEtoM(feet, inches);
    outputEnglish(meters, feet, inches);
}

void inputEnglish(double& f, double& i){
    bool valid = false;

    while (!valid) {
        cout << "Enter number of feet of as a double: ";
        cin >> f;
        cout << "Enter number of inches as a double: ";
        cin >> i;

        if (checkIfValid(f) && checkIfValid(i))
            valid = true;
        else {
            cout << englishError << "\n";
        }
    }
}

double convertEtoM(int f, double i){
    return (f + (i * inches_to_feet)) * english_to_metric_factor;
}

void outputEnglish(double m, int f, double i){
    cout << f << " feet, " << i << " inches corresponds to " << m << " meters" << "\n\n";
}
