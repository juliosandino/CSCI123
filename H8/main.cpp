#include <iostream>
using namespace std;

void stringToArray(string str, char arr[]);

int main() {
    string firstName;
    string middleName;
    string lastName;

    cout << "What is your first name?";
    cin >> firstName;

    char firstNameArr[firstName.length()];

    stringToArray(firstName, firstNameArr);

    cout << "What is your Middle name?";
    cin >> middleName;

    char middleNameArr[middleName.length()];

    stringToArray(middleName, middleNameArr);

    cout << "What is your first name?";
    cin >> lastName;

    char lastNameArr[lastName.length()];

    stringToArray(lastName, lastNameArr);

    cout << lastNameArr[0];
}

void stringToArray(string str, char arr[]){
    for (int i = 0; i < str.length(); i++)
        arr[i] = str.at(i);
}



