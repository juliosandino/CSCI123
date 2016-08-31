//P1.cpp
//Programmer: Julio Sandino                                             CSCI 123, Fall 2016
//Project 1                                                             Instructor: Mai, Timothy
//Due Date: 9/20/16                                                     Date Submitted: 9/20/16

//Program Description: This program is able to convert the units from metric to english and vice versa
//It employs for loops, static methods, and user input

#include <iostream>
using namespace std;

void menu();
void englishToMetric(double value);
void metricToEnglish(double value);

string choice;
int main() {

    menu();
    cin >> choice;

    if (choice == "1"){
        int value;
        cout << "Enter a number of meters as a double: ";
        cin >> value;
        metricToEnglish(value);
    } else if(choice == "2"){
        double value;
        cout << "Enter number of feet of as a double: ";
        cin >> value;
        englishToMetric(value);
    } else if(choice == "3"){
        //do something
        cout << "Goodbye!";
    } else {
        cout << "Invalid choice! please choose a number between 1 and 3" << endl << endl;
        choice.clear();
        main();
    }
    return 0;
}

void menu(){
    string option1 = "1. Convert length from Metric to English";
    string option2 = "2. Convert length from English to Metric";
    string option3 = "3. Quit the Program";

    string option[] = {option1, option2, option3};

    cout << "Menu" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << option[i] << endl;
    }
    cout << "Please enter your choice:  ";
}

void metricToEnglish(double value){
    double calculation;

    calculation = value * (1.00 / 0.3084);
    cout << value << " meters corresponds to " << calculation << " feet" << endl;
}

void englishToMetric(double value){
    double calculation;

    calculation = value * 0.3084;
    cout << value << " feet corresponds to " << calculation << " meters" << endl;
}