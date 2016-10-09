//
// Created by Abhiraj Deshpande on 10/7/16.
//

#include <iostream>
#include <sstream>

using namespace std;

int main() {

    cout << "Enter the dimension of the square matrix: ";
    string strDimension;
    int iDimension;
    getline(cin , strDimension);
    iDimension = atoi(strDimension.c_str());

    int iarrMatrix[iDimension][iDimension];

    cout << "Enter the matrix values:" << endl;

    int iRow = 0;
    int iColumn = 0;
    do {
        string strValues;
        getline(cin, strValues);

        istringstream issInput(strValues);
        for (string strValues; issInput >> strValues;) {
            iarrMatrix[iRow][iColumn] = atoi(strValues.c_str());
            iColumn++;
        }

        iColumn = 0;
        iRow++;

        // To break the input
        if (strValues == "") {
            break;
        }
    } while (cin);


    for (int iEdge = 0; iEdge < iDimension / 2; iEdge++) {

        int iFirst = iEdge;
        int iLast = iDimension - 1 - iEdge;

        for (int iIndex = iFirst; iIndex < iLast; iIndex++) {
            int iOffset = iIndex - iFirst;

            // Store top
            int iTemp = iarrMatrix[iFirst][iIndex];
            // Left to Top
            iarrMatrix[iFirst][iIndex] = iarrMatrix[iLast - iOffset][iFirst];
            // Bottom to Left
            iarrMatrix[iLast - iOffset][iFirst] = iarrMatrix[iLast][iLast - iOffset];
            // Right to Bottom
            iarrMatrix[iLast][iLast - iOffset] = iarrMatrix[iIndex][iLast];
            // Temp to Right
            iarrMatrix[iIndex][iLast] = iTemp;
        }
    }

    cout << "The matrix after 90 degree rotation " << endl;
    for (int iRow = 0; iRow < iDimension; iRow++) {
        for (int iColumn = 0; iColumn < iDimension; iColumn++) {
            cout << iarrMatrix[iRow][iColumn] << "\t";
        }
        cout << endl;
    }

    return 0;
}