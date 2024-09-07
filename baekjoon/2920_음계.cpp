#include <iostream>
using namespace std;
int mode;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 1, j; i <= 8; ++i)
    {
        cin >> j;
        if (i == j)
        {
            mode |= 1;
        }
        else if (i == 9 - j)
        {
            mode |= 2;
        }
        else
        {
            mode |= 4;
        }
    }

    switch (mode)
    {
    case 1:
        cout << "ascending";
        break;
    case 2:
        cout << "descending";
        break;
    default:
        cout << "mixed";
        break;
    }
    return 0;
}