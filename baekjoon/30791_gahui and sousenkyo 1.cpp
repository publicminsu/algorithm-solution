#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int high, i = 0, low;
    cin >> high;
    for (; i < 4; ++i)
    {
        cin >> low;
        if (high - 1000 > low)
        {
            break;
        }
    }
    cout << i;
    return 0;
}