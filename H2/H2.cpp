//H2.cpp
//Programmer: Julio Sandino                                             CSCI 123, Fall 2016
//Homework 2                                                            Instructor: Mai, Timothy
//Due Date: 9/08/16                                                     Date Submitted: 9/08/16

//Program Description:
//1. It prints out my name(Julio Sandino) 10 times
//2. It takes in an integer from user input and it calculates an expression with it and the answer to the console.

#include <iostream>
using namespace std;

static void expression_calculator(int x);
static void loop();

int main() {

    loop();

    int value;

    //getting the user input to use for expression_calculator
    cout << "Please enter a positive integer: ";
    cin >> value;

    expression_calculator(value);

    return 0;
}

//this function prints out my name 10 times with a for loop
static void loop(){
    for (int i = 1; i <= 10; ++i) {
        cout << i << " Julio Sandino" << endl;
    }
}

//this function uses the argument int x to make a calculation to the console.
static void expression_calculator(int x){
    int answer;

    answer = ((x / 3) + (x % 3)) * 3;

    //the answer that will be printed to the console.
    cout << "((" << x << "/3) + (" << x <<"%3)) * 3 = " << answer;
}


