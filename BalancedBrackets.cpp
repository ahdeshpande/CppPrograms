#include <iostream>
#include <stack>

using namespace std;

int main() {
    string strInput = "";
    cout << "Enter a string: ";
    cin >> strInput;

    stack<char> stkOpeningBrackets;
    bool  isBalanced = true;

    for(int i=0; i<strInput.size(); i++)
    {
        // Check for opening brackets, push it onto stack
        if(strInput.at(i) == '{' || strInput.at(i) == '(' || strInput.at(i) == '[')
        {
            stkOpeningBrackets.push(strInput.at(i));
        }
            // If closing brackets, check if stack has a matching opening bracket at top
        else if(strInput.at(i) == '}' || strInput.at(i) == ')' || strInput.at(i) == ']')
        {
            // If closing bracket detected without matching opening bracket, break;
            if(stkOpeningBrackets.empty())
            {
                isBalanced = false;
            }
            else
            {
                // Switch to check for individual brackets
                switch (strInput.at(i))
                {
                    case '}':
                    {
                        if(stkOpeningBrackets.top() == '{')
                        {
                            isBalanced = true;
                            stkOpeningBrackets.pop();
                        }
                        else
                        {
                            isBalanced = false;
                        }
                        break;
                    }
                    case ')':
                    {
                        if(stkOpeningBrackets.top() == '(')
                        {
                            isBalanced = true;
                            stkOpeningBrackets.pop();
                        }
                        else
                        {
                            isBalanced = false;
                        }
                        break;
                    }
                    case ']':
                    {
                        if(stkOpeningBrackets.top() == '[')
                        {
                            isBalanced = true;
                            stkOpeningBrackets.pop();
                        }
                        else
                        {
                            isBalanced = false;
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

            if(!isBalanced)
                break;
        }
    }

    cout << strInput << " = " << boolalpha << isBalanced;

    return 0;
}