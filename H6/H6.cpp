#include <iostream>
#include <fstream>
using namespace std;

bool isLower(char letter);
bool isUpper(char letter);
bool isNumber(char letter);

int main(){
    string line;
    string outputLine;
    fstream inputFile;
    fstream outputFile;

    int uppercaseLetters;
    int lowercaseLetters;

    inputFile.open("cad.dat");
    outputFile.open("outputs.dat");

    //checks to see if the files exist
    if (inputFile.is_open() && outputFile.is_open()){
        //loops through every line in the file
        while (getline(inputFile, line)){
            //loops through every character in the line
            for (int i = 0; i < line.length(); i++) {

                char character = line.at(i);

                if (isLower(character)) {
                    line.at(i) = toupper(character);
                    lowercaseLetters++;
                }
                else if(isUpper(character)){
                    line.at(i) = tolower(character);
                    uppercaseLetters++;
                }
                else if (character == ' '){
                    line.at(i) = '-';
                }
                else if(isNumber(character)){
                    line.at(i) = '#';
                }
            }

            //adds the modified line to the output file
            outputFile << line << endl;
        }
        outputFile.close();
        inputFile.close();

        cout << "Uppercase letters: " << uppercaseLetters << endl;
        cout << "Lowercase letters: " << lowercaseLetters << endl;
    }

    else {
        cout << "Unable to open input file or output file\n";
    }
}

//checks if the character is lowercase
bool isLower(char letter){
    if (letter >= 97 && letter <= 122)
        return true;
    else
        return false;
}

//checks if the character is uppercase
bool isUpper(char letter){
    if (letter >= 65 && letter <= 90)
        return true;
    else
        return false;
}

//checks if the character is a number
bool isNumber(char letter){
    if(letter >= 48 && letter <= 57)
        return true;
    else
        return false;
}