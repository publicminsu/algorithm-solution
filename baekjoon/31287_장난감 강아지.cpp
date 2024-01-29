#include <iostream>
using namespace std;
string str;
int curY, curX, N, K;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    cin >> str;

    if (K > (N >> 1))
    {
        K = (N >> 1);
    }
    while (K--)
    {
        for (char c : str)
        {
            if (c == 'U')
            {
                ++curY;
            }
            else if (c == 'D')
            {
                --curY;
            }
            else if (c == 'L')
            {
                --curX;
            }
            else
            {
                ++curX;
            }
            if (curY == 0 && curX == 0)
            {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}
