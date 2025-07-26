#include <iostream>
#include <stack>
using namespace std;

string num1, num2;
stack<int> answer;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> num1 >> num2;

    int i = num1.size() - 1;
    int j = num2.size() - 1;
    bool carry = false;

    while (i >= 0 || j >= 0)
    {
        int sum = carry;

        if (i >= 0)
        {
            sum += (num1[i--] - '0');
        }

        if (j >= 0)
        {
            sum += (num2[j--] - '0');
        }

        if (sum >= 2)
        {
            carry = true;
            sum -= 2;
        }
        else
        {
            carry = false;
        }

        answer.push(sum);
    }

    if (carry)
    {
        cout << 1;
    }
    else
    {
        while (answer.size() > 1 && answer.top() == 0)
        {
            answer.pop();
        }
    }

    while (!answer.empty())
    {
        cout << answer.top();
        answer.pop();
    }
    return 0;
}