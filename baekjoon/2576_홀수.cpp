#include <iostream>
using namespace std;
int sum, minNum = 100;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0, j; i < 7; ++i)
    {
        cin >> j;

        if (j % 2)
        {
            sum += j;
            minNum = min(minNum, j);
        }
    }

    if (sum)
    {
        cout << sum << "\n"
             << minNum;
    }
    else
    {
        cout << -1;
    }
    return 0;
}