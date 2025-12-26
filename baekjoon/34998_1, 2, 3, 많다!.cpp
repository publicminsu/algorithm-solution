#include <iostream>

using namespace std;

int T, X;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;

    while (T--)
    {
        cin >> X;

        int sum = 0;

        for (int i = 0; i < X * 2 + 1; ++i)
        {
            char c;
            cin >> c;

            if (i % 2 == 0)
            {
                if (c == '!')
                {
                    sum = 10;
                }
                else
                {
                    sum += c - '0';
                }
            }
        }

        if (sum >= 10)
        {
            cout << '!';
        }
        else
        {
            cout << sum;
        }

        cout << "\n";
    }
    return 0;
}