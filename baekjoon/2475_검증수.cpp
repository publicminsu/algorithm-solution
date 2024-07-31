#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int sum = 0;

    for (int i = 0, j; i < 5; ++i)
    {
        cin >> j;
        sum += j * j;
    }

    cout << sum % 10;
    return 0;
}