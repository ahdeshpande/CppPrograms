//
// Created by Abhiraj Deshpande on 10/6/16.
//

#include <iostream>
#include <sstream>

using namespace std;


int main() {

    // Get all the numbers of the array
    cout << "Enter the numbers: " << endl;
    string strValues;
    getline(cin, strValues);

    int iarrNumbers[] = {};
    int iCount = 0;

    istringstream issInput(strValues);
    for (string strValues; issInput >> strValues;) {
        iarrNumbers[iCount] = atoi(strValues.c_str());
        iCount++;
    }

    // Create 2 arrays to store the sum of the cumulative sum of the array numbers
    int iarrFrontSum[iCount];
    int iarrRearSum[iCount];

    // Add the first numbers from first and last to the first index of Front and Rear respectively
    iarrFrontSum[0] = iarrNumbers[0];
    iarrRearSum[0] = iarrNumbers[iCount - 1];

    // Iterate through the array and perform cumulative sum from front and back
    for (int iIndex = 1; iIndex < iCount; iIndex++) {
        iarrFrontSum[iIndex] = iarrFrontSum[iIndex - 1] + iarrNumbers[iIndex];
        iarrRearSum[iIndex] = iarrRearSum[iIndex - 1] + iarrNumbers[iCount - 1 - iIndex];
    }

    bool isPresent = false;
    // Compare the 2 arrays
    // Iterate such that front == rear - 1: if equal, then that is the balanced node
    for (int iIndex = 0; iIndex < iCount; iIndex++) {
        if (iarrFrontSum[iIndex] == iarrRearSum[iCount - 2 - iIndex]) {
            isPresent = true;
            cout << to_string(iIndex) << "\t";
        }
    }

    // Check if sum of all elements is 0, then the array is balanced on the last index
    if (iarrFrontSum[iCount - 1] == 0) {
        isPresent = true;
        cout << iCount - 1;
    }

    // If no balanced index
    if (!isPresent)
        cout << "None";

    return 0;
}