#include <iostream>
using namespace std;
char prevC, c;
int total = 1, zero;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> prevC;

    if (prevC == '0')
    {
        zero = 1;
    }

    while (cin >> c)
    {
        if (c != prevC)
        {
            ++total;

            if (c == '0')
            {
                ++zero;
            }
        }

        prevC = c;
    }

    cout << min(total - zero, zero);
    return 0;
}