//
// Created by Abhiraj Deshpande on 10/6/16.
//

#include <iostream>

using namespace std;

string CompressedString(string strString) {
    string strCompressed = "";

    int iLengthOriginal = strString.length();

    int iIndex = 0;
    int iCount = 0;
    char charC;
    bool hasRepetition = false;

    // Iterate till end of string
    while (iIndex < iLengthOriginal) {

        // Take the character and see if it has any consecutive repetition
        charC = strString.at(iIndex);
        iCount = 1;
        strCompressed = strCompressed + charC;
        iIndex++;

        // Check for the next positions till character doesn't match
        // Change flag to true if repetition exists
        while (iIndex < iLengthOriginal) {
            if (charC == strString.at(iIndex)) {
                iCount++;
                iIndex++;
                hasRepetition = true;
            } else {
                break;
            }
        }
        // Add the count after the character
        strCompressed = strCompressed + to_string(iCount);
    }

    // If flag is false, return same string
    if (!hasRepetition) {
        return strString;
    } else {
        return strCompressed;
    }

}

int main() {
    // Input string
    cout << "Enter the string : ";
    string strString;
    getline(cin, strString);

    cout << "Compressed string of " << strString << " is " << CompressedString(strString) << endl;

    return 0;
}