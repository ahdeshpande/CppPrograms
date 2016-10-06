//
// Created by Abhiraj Deshpande on 10/5/16.
//

#include <list>
#include <sstream>
#include "iostream"

using namespace std;

// Function to calculate the cycle length of the number
int CalculateCycleLength(int iNumber) {
    int iCycleLength = 1;

    // number even : divide by 2
    // number odd : multiply by 3 and add 1
    while (iNumber != 1) {
        if (iNumber % 2 == 0) {
            iNumber = iNumber / 2;
        } else {
            iNumber = (iNumber * 3) + 1;
        }
        iCycleLength++;
    }

    return iCycleLength;
}

int main() {

    list<string> lstrValues;
    cout << "Enter the pairs of integers: " << endl;

    // For input
    // Store the lower and upper bound of the range in the list
    do {
        string strValues;
        getline(cin, strValues);

        istringstream issInput(strValues);
        for (string strValues; issInput >> strValues;) {
            lstrValues.push_back(strValues);
        }

        // To break the input
        if (strValues == "") {
            break;
        }
    } while (cin);

    // Array for lower and upper bound
    int iarrValues[2];

    // Iterate and read the bounds
    list<string>::iterator itSeries;
    for (itSeries = lstrValues.begin(); itSeries != lstrValues.end();) {
        int iMaxCycleLength = 0;

        int iIndex = 0;
        // Lower bound
        iarrValues[iIndex] = atoi((*itSeries).c_str());
        iIndex++;
        itSeries++;
        // Upper bound
        iarrValues[iIndex] = atoi((*itSeries).c_str());
        itSeries++;

        // Calculate the cycle length for all values in the bounds
        for (int i = iarrValues[0]; i <= iarrValues[1]; i++) {
            int iCycleLength = CalculateCycleLength(i);
            if (iMaxCycleLength < iCycleLength)
                iMaxCycleLength = iCycleLength;
        }

        cout << iarrValues[0] << " " << iarrValues[1] << " " << iMaxCycleLength << endl;
    }
    return 0;
}