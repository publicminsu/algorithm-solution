#include <iostream>
using namespace std;

int day, cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> day;

    for (int i = 0; i < 5; ++i)
    {
        int car;
        cin >> car;

        if (car == day)
        {
            ++cnt;
        }
    }

    cout << cnt;
    return 0;
}