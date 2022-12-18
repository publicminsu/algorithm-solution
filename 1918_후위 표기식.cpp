#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    stack<char> opStack;
    string infix, postfix = "";
    cin >> infix;
    for (char c : infix)
    {
        if (c >= 'A' && c <= 'Z')
        {
            postfix += c;
        }
        else if ((c == '+' || c == '-'))
        {
            while (!opStack.empty())
            {
                if (opStack.top() == '(')
                    break;
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
        else if ((c == '*' || c == '/'))
        {
            if (!opStack.empty() && (opStack.top() == '*' || opStack.top() == '/'))
            {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
        else if (c == ')')
        {
            while (!opStack.empty())
            {
                if (opStack.top() == '(')
                {
                    opStack.pop();
                    break;
                }
                postfix += opStack.top();
                opStack.pop();
            }
        }
        else
        {
            opStack.push(c);
        }
    }
    while (!opStack.empty())
    {
        postfix += opStack.top();
        opStack.pop();
    }
    cout << postfix;
    return 0;
}