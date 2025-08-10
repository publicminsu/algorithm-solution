#include <iostream>
#include <stack>
using namespace std;

int solve()
{
    string str;
    stack<char> st;
    int sum = 0, value = 1;

    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str;

    for (int i = 0; i < str.size(); ++i)
    {
        const char &c = str[i];

        switch (c)
        {
        case '(':
            st.push(c);
            value *= 2;
            break;
        case '[':
            st.push(c);
            value *= 3;
            break;
        case ')':
            if (st.empty() || st.top() != '(')
            {
                return 0;
            }
            else if (str[i - 1] == '(')
            {
                sum += value;
                value /= 2;
                st.pop();
            }
            else
            {
                value /= 2;
                st.pop();
            }
            break;
        case ']':
            if (st.empty() || st.top() != '[')
            {
                return 0;
            }
            else if (str[i - 1] == '[')
            {
                sum += value;
                value /= 3;
                st.pop();
            }
            else
            {
                value /= 3;
                st.pop();
            }
            break;
        }
    }

    if (!st.empty())
    {
        return 0;
    }

    return sum;
}

int main()
{
    cout << solve();
    return 0;
}