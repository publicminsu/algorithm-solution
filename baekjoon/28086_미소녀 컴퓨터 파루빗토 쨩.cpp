#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
string str;
ll leftValue, rightValue, result, answer;
char op;
bool isRight, isLeftNegative, isRightNegative;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.size(); ++i)
    {
        const char &c = str[i];

        if (isRight)
        {
            if ('0' <= c && '9' >= c)
            {
                rightValue *= 8;

                if (isRightNegative)
                {
                    rightValue -= (c - '0');
                }
                else
                {
                    rightValue += (c - '0');
                }
            }
            else
            {
                isRightNegative = true;
            }
        }
        else
        {
            if ('0' <= c && '9' >= c)
            {
                leftValue *= 8;

                if (isLeftNegative)
                {
                    leftValue -= (c - '0');
                }
                else
                {
                    leftValue += (c - '0');
                }
            }
            else
            {
                if (i == 0)
                {
                    isLeftNegative = true;
                }
                else
                {
                    isRight = true;
                    op = c;
                }
            }
        }
    }

    switch (op)
    {
    case '+':
        result = leftValue + rightValue;
        break;

    case '-':
        result = leftValue - rightValue;
        break;

    case '*':
        result = leftValue * rightValue;
        break;

    case '/':
        if (rightValue == 0)
        {
            cout << "invalid";
            return 0;
        }

        result = floor((float)leftValue / rightValue);
        break;
    }

    ll i = 1;

    while (result)
    {
        answer += i * (result % 8);
        i *= 10;
        result /= 8;
    }

    cout << answer;
    return 0;
}