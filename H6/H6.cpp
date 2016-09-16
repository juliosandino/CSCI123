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

    inputFile.open ("/Users/julio395/ClionProjects/csci123/H6/cad.dat");
    outputFile.open("/Users/julio395/ClionProjects/csci123/H6/outputs.dat");

    if (inputFile.is_open()){
        while (getline(inputFile, line)){
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

            outputLine = line;
            cout << "Uppercase letters: " << uppercaseLetters << endl;
            cout << "Lowercase letters: " << lowercaseLetters << endl;
            cout << line;
        }
        inputFile.close();
    }

    else {
        cout << "Unable to open input file\n";
    }

    if (outputFile.is_open()){
        outputFile << outputLine;
        outputFile.close();
    }
    else{
        cout << "Unable to open output file\n";
    }
}

bool isLower(char letter){
    if (letter >= 97 && letter <= 122)
        return true;
    else
        return false;
}
bool isUpper(char letter){
    if (letter >= 65 && letter <= 90)
        return true;
    else
        return false;
}

bool isNumber(char letter){
    if(letter >= 48 && letter <= 57)
        return true;
    else
        return false;
}