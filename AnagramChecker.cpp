//
// Created by Abhiraj Deshpande on 10/6/16.
//

#include <iostream>

using namespace std;

void sortString(char *ptrcharString) {
    // Calculate the length of the string
    int iLength = 0;
    int iIndex = 0;
    while (ptrcharString[iIndex] != '\0') {
        iLength++;
        iIndex++;
    }

    char temp;

    // Sort the string
    for (int iOuterIndex = 0; iOuterIndex < iLength - 1; iOuterIndex++) {
        for (int iInnerIndex = 0; iInnerIndex < iLength - iOuterIndex - 1; iInnerIndex++) {
            if ((int) ptrcharString[iInnerIndex] > (int) ptrcharString[iInnerIndex + 1]) {
                temp = ptrcharString[iInnerIndex];
                ptrcharString[iInnerIndex] = ptrcharString[iInnerIndex + 1];
                ptrcharString[iInnerIndex + 1] = temp;
            }
        }
    }
}


int main() {
    // Input string
    cout << "Enter the first string : ";
    string strString1;
    cin >> strString1;

    cout << "Enter the second string : ";
    string strString2;
    cin >> strString2;

    // Check if the strings are of same length
    if (strString1.length() == strString2.length()) {
        // Convert to char array
        char chararrString1[strString1.length()+1];
        strncpy(chararrString1, strString1.c_str(), sizeof(chararrString1));

        char chararrString2[strString2.length()+1];
        strncpy(chararrString2, strString2.c_str(), sizeof(chararrString2));

        // Sort the string
        sortString(chararrString1);
        string strSorted1 = chararrString1;
        sortString(chararrString2);
        string strSorted2 = chararrString2;

        // Check if the sorted strings are same
        if (strSorted1 == strSorted2)
            cout << strString2 << " is a permutation of " << strString1;
        else
            cout << strString2 << " is not a permutation of " << strString1;
    } else {
        cout << strString2 << " and " << strString1 << " are of different lengths";
    }
    return 0;
}