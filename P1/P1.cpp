//P1.cpp
//Programmer: Julio Sandino                                             CSCI 123, Fall 2016
//Project 1                                                             Instructor: Mai, Timothy
//Due Date: 9/20/16                                                     Date Submitted: 9/20/16

//Program Description: This program is able to convert the units from metric to english and vice versa
//It employs for loops, static methods, and user input

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

//declaring the methods that we will use
//this method prints out the menu to the user
static void menu();

static void englishToMetric(double feet, double inches);
static void metricToEnglish(double value);

//this method checks if the values the user inputed are valid for calcuations
//if the double is not greater than or equal to 0 it will return an error
static bool checkIfValid(double value);

string choice;
int main() {

    menu();
    cin >> choice;

    if (choice == "1"){
        double meters;
        cout << "Enter a number of meters as a double: ";
        cin >> meters;

        if (checkIfValid(meters)){
            metricToEnglish(meters);
        } else {
            cout << metricError << endl << endl;
            choice.clear();
            main();
        }
    } else if(choice == "2"){
        //variables we'll need in order to calculate
        double feet;
        double inches;

        cout << "Enter number of feet of as a double: ";
        cin >> feet;
        cout << "Enter number of inches as a double: ";
        cin >> inches;

        if (checkIfValid(feet) && checkIfValid(inches)){
            englishToMetric(feet, inches);
        } else {
            cout << englishError << endl << endl;
            choice.clear();
            main();
        }

    } else if(choice == "3"){
        //do something
        cout << "Goodbye!";
    } else {
        cout << choiceError << endl << endl;
        choice.clear();
        main();
    }
    return 0;
}

//the \t is for formatting purposes. it puts a tab inside the string
static void menu(){
    cout << "\tMenu" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i+1 << ".\t" << option[i] << endl;
    }
    cout << "Please enter your choice:  ";
}

static void metricToEnglish(double value){
    //declaring the output variables
    double calculation;
    double feet;
    double inches;

    //giving value to the variables that will be outputted
    calculation = value * metric_to_english_factor;
    feet = floor (calculation);
    inches = round ((calculation - feet) * 100 * feet_to_inches) / 100;

    //outputting the result to the user
    cout << value << " meters corresponds to " << feet << " feet, " << inches << " inches" << endl;
}

static void englishToMetric(double feet, double inches){

    double meters = (feet + (inches * inches_to_feet)) * english_to_metric_factor;

    //prints out the value to the users
    cout << feet << " feet, " << inches << " inches corresponds to " << meters << " meters" << endl;
}

static bool checkIfValid(double value){
    return value >= 0;
}