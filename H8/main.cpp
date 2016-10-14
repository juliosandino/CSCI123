#include <iostream>
using namespace std;

void stringToArray(string str, char arr[]);

int main() {
    string firstName;
    string middleName;
    string lastName;

    cout << "What is your first name? ";
    cin >> firstName;

    char firstNameArr[firstName.length()];

    stringToArray(firstName, firstNameArr);

    cout << "What is your middle name? ";
    cin >> middleName;

    char middleNameArr[middleName.length()];

    stringToArray(middleName, middleNameArr);

    cout << "What is your last name? ";
    cin >> lastName;

    char lastNameArr[lastName.length()];

    stringToArray(lastName, lastNameArr);

    int fullNameLength = firstName.length() + middleName.length() + lastName.length() + 3;

    char FullName[fullNameLength];

    char space[] = " ";

    strcat(FullName, firstNameArr);
    strcat(FullName, space);
    strcat(FullName, middleNameArr);
    strcat(FullName, space);
    strcat(FullName, lastNameArr);

    cout << FullName << endl;
    cout << "Total number of characters: " << fullNameLength - 3;
}

void stringToArray(string str, char arr[]) {
    for (int i = 0; i < str.length(); i++)
        arr[i] = str.at(i);
}



