//
// Created by Abhiraj Deshpande on 10/7/16.
//

#include <iostream>

using namespace std;

// Check if string is substring
bool IsSubstring(string strMainString, string strSubString) {
    bool isSubString = false;

    if (strMainString.find(strSubString) != string::npos) {
        isSubString = true;
    }

    return isSubString;
}

int main() {
    // Input string
    cout << "Enter the first string : ";
    string strString1;
    cin >> strString1;

    cout << "Enter the second string : ";
    string strString2;
    cin >> strString2;

    // Append the main string to the main string again, e.g. notebooknotebook
    // This will make sure all the rotations are a substring of this string
    string strNewString = strString1 + strString1;
    bool isRotation = IsSubstring(strNewString, strString2);

    if (isRotation) {
        cout << strString2 << " is a rotation of " << strString1;
    } else {
        cout << strString2 << " is a not rotation of " << strString1;
    }

    return 0;
}