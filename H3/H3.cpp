//H3.cpp
//Programmer: Julio Sandino                                             CSCI 123, Fall 2016
//Homework 3                                                            Instructor: Mai, Timothy
//Due Date: 9/20/16                                                     Date Submitted: 9/20/16

//Program Description: The program prints numbers from 0 to 10, 3 times, while also printing the run number.

#include <iostream>
using namespace std;

int main(){

    //Outer loop that handles the "Run#.."
    for (int i = 1; i <= 3; ++i) {
        cout << "Run#" << i << ": ";

        //Inner loop that handles the 1 2 3 4...
        for (int j = 1; j <= 10 ; ++j) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}