//H1.cpp
//Programmer: Julio Sandino                                             CSCI 123, Fall 2016
//Homework 1                                                            Instructor: Mai, Timothy
//Due Date: 8/30/16                                                     Date Submitted: 8/30/16

//Program Description: This program takes two integers from user input and prints out the sum of the two.

#include <iostream>
using namespace std;

int main(void)
{
    int x, y, sum;
    cout << "Enter two integers..seperated by a space: ";
    cin >> x >> y;

    sum = x + y;

    cout << "The sum of the two numbers " << x << " " << y <<" is " << sum ;
    cout << endl;

    return 0;

}