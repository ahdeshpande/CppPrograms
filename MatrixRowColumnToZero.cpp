//
// Created by Abhiraj Deshpande on 10/7/16.
//

#include <iostream>
#include <sstream>
#include <list>

using namespace std;

int main() {

    cout << "Enter the dimensions of the matrix (row column): ";
    string strDimension;
    int iRowD, iColD;
    getline(cin, strDimension);
    istringstream issInput(strDimension);
    int iIndex = 0;
    for (string strValues; issInput >> strDimension;) {
        if (iIndex == 0)
            iRowD = atoi(strDimension.c_str());
        else
            iColD = atoi(strDimension.c_str());
        iIndex++;
    }

    int iarrMatrix[iRowD][iColD];

    list<string> lstrRowNumber;
    list<string> lstrColNumber;

    cout << "Enter the matrix values:" << endl;

    int iRow = 0;
    int iColumn = 0;
    do {
        string strValues;
        getline(cin, strValues);

        istringstream issInput(strValues);
        for (string strValues; issInput >> strValues;) {
            iarrMatrix[iRow][iColumn] = atoi(strValues.c_str());

            // Store the index if the element is zero
            if (iarrMatrix[iRow][iColumn] == 0) {
                lstrRowNumber.push_back(to_string(iRow));
                lstrColNumber.push_back(to_string(iColumn));
            }
            iColumn++;

        }

        iColumn = 0;
        iRow++;

        // To break the input
        if (strValues == "") {
            break;
        }
    } while (cin);

    // Make the Row Zero
    list<string>::iterator litMatrix;
    for (litMatrix = lstrRowNumber.begin(); litMatrix != lstrRowNumber.end(); litMatrix++) {
        for (int iColumn = 0; iColumn < iColD; iColumn++) {
            iarrMatrix[atoi((*litMatrix).c_str())][iColumn] = 0;
        }
    }

    // Make the Column Zero
    for (litMatrix = lstrColNumber.begin(); litMatrix != lstrColNumber.end(); litMatrix++) {
        for (int iRow = 0; iRow < iColD; iRow++) {
            iarrMatrix[iRow][atoi((*litMatrix).c_str())] = 0;
        }
    }

    // Print
    cout << "The updated matrix " << endl;
    for (int iRow = 0; iRow < iRowD; iRow++) {
        for (int iColumn = 0; iColumn < iColD; iColumn++) {
            cout << iarrMatrix[iRow][iColumn] << "\t";
        }
        cout << endl;
    }

    return 0;
}