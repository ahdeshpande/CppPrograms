//
// Created by Abhiraj Deshpande on 10/6/16.
//

#include <iostream>

using namespace std;


// Implement a function void reverse(char* str) which reverses a null-terminated string

void reverse(char *ptrcharString) {

    // Calculate the length of the string
    int iLength = 0;
    int iIndex = 0;
    while (ptrcharString[iIndex] != '\0') {
        iLength++;
        iIndex++;
    }

    char strReverse[iLength];

    // Reverse the string
    int iReversalIndex = 0;
    for (int iIndex = iLength - 1; iIndex >= 0; iIndex--) {
        strReverse[iReversalIndex] = ptrcharString[iIndex];
        iReversalIndex++;
    }

    // Copy to the original char*
    strcpy(ptrcharString, strReverse);
}

int main() {
    // Input string
    char strInput[] = "";
    cout << "Enter the string : ";
    cin >> strInput;

    char *ptrcharString = strInput;
    reverse(ptrcharString);

    // Print the output
    cout << "Reverse is " << ptrcharString;
    return 0;
}