#include <iostream>
using namespace std;
int index, maxNum;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 1, j; i <= 9; ++i)
    {
        cin >> j;

        if (maxNum < j)
        {
            maxNum = j;
            index = i;
        }
    }

    cout << maxNum << "\n"
         << index;
    return 0;
}