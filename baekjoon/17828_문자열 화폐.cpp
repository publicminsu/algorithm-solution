#include <iostream>
#include <stack>
using namespace std;

int N, X;
stack<char> st;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> X;

    if (N > X)
    {
        cout << '!';
        return 0;
    }

    while (st.size() < N)
    {
        int remainLen = N - st.size();

        if (X == remainLen)
        {
            for (int i = 0; i < X; ++i)
            {
                st.push('A');
            }
            X = 0;
        }
        else
        {
            int remainValue = X - remainLen + 1;
            if (remainValue >= 26)
            {
                st.push('Z');
                X -= 26;
            }
            else
            {
                st.push('A' + remainValue - 1);
                X -= remainValue;
            }
        }
    }

    if (X == 0 && st.size() == N)
    {
        while (!st.empty())
        {
            cout << st.top();
            st.pop();
        }
    }
    else
    {
        cout << '!';
    }
    return 0;
}