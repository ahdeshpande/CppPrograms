//
// Created by Abhiraj Deshpande on 10/6/16.
//

#include <iostream>

using namespace std;

int main() {
    // Input string
    cout << "Enter the string : ";
    string strString;
    getline(cin, strString);

    // Count spaces
    int iSpaces = 0;
    for (int iIndex = 0; iIndex < strString.length(); iIndex++) {
        if (strString.at(iIndex) == ' ') {
            iSpaces++;
        }
    }

    // Convert to char array
    char chararrOriginalString[strString.length() + 1];
    strncpy(chararrOriginalString, strString.c_str(), sizeof(chararrOriginalString));

    // New Char array has 2*Spaces additional length
    char chararrNewString[strString.length() + 1 + (2 * iSpaces)];

    // Iterate and copy character from old to new array
    // If blank detected, inset %20
    int iNewStringIndex = 0;
    for (int iIndex = 0; iIndex < strString.length(); iIndex++) {
        if (chararrOriginalString[iIndex] == ' ') {
            chararrNewString[iNewStringIndex] = '%';
            iNewStringIndex++;
            chararrNewString[iNewStringIndex] = '2';
            iNewStringIndex++;
            chararrNewString[iNewStringIndex] = '0';
        } else {
            chararrNewString[iNewStringIndex] = chararrOriginalString[iIndex];
        }
        iNewStringIndex++;
    }

    // Print the Output
    cout << chararrNewString << endl;

    return 0;
}