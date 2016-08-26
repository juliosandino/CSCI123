//H4.cpp
//Programmer: Julio Sandino                                             CSCI 123, Fall 2016
//Homework 4                                                            Instructor: Mai, Timothy
//Due Date: 9/27/16                                                     Date Submitted: 9/27/16

//Program Description:


#include <iostream>
using namespace std;

int total (int);
int factorial (int);

int main () {
    int n;
    cout << "Please enter a positive number: ";
    cin >> n;

    cout << "The total from 1 to "<< n <<": "<< total(n) << endl;
    cout << "The factorial of "<< n << ": "<< factorial(n) << endl;

    return 0;
}

int total (int n) {
    int total_sum = 0;

    while (n > 0){
        total_sum = total_sum + n;
        --n;
    }

    return total_sum;
}

int factorial (int n) {
    int total = 1;

    for (int i = n; i > 1; --i) {
        total = total * i;
    }

    return total;
}