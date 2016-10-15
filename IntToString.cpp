//
// Created by Abhiraj Deshpande on 10/15/16.
//

#include <iostream>

using namespace std;

int main() {

    // Input Number
    cout << "Enter the number to be converted to string: ";
    int iNum;
    cin >> iNum;

    // String to store number
    string strNum = "";
    int iDigit = 0;

    // Continue to retrieve individual digit
    while (iNum != 0) {

        iDigit = iNum % 10;
        // Insert the digit at position 0
        strNum.insert(0, 1, '0' + iDigit);
        iNum = iNum / 10;

    }
    cout << "Number is " << strNum << endl;
    return 0;
}