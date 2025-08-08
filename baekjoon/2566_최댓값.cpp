#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int maxNum = -1;
    int y, x;

    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            int num;
            cin >> num;

            if (num > maxNum)
            {
                maxNum = num;
                y = i;
                x = j;
            }
        }
    }

    cout << maxNum << "\n"
         << y << " " << x;

    return 0;
}