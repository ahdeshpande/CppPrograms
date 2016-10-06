//
// Created by Abhiraj Deshpande on 10/5/16.
//

#include "iostream"

using namespace std;

int main() {

    // Input string
    string strInput = "";
    cout << "Enter the string :";
    cin >> strInput;

    // Flag to notify if unique
    bool isUnique = true;

    // Iterate and check if the first index and the last index of the character is same, if not then no unique
    for (int iIndex = 0; iIndex < strInput.length(); iIndex++) {
        if (strInput.find_first_of(strInput.at(iIndex)) != strInput.find_last_of(strInput.at(iIndex))) {
            isUnique = false;
            break;
        }
    }

    // Print the result
    if (isUnique)
        cout << strInput << " has all unique characters.";
    else
        cout << strInput << " does not have all unique characters.";

    return 0;
}