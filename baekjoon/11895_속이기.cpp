#include <iostream>
using namespace std;

int n;
int sumValue, minValue = 1000000, xorValue;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    for (int i = 0, a; i < n; ++i)
    {
        cin >> a;
        sumValue += a;
        minValue = min(minValue, a);
        xorValue ^= a;
    }

    if (xorValue)
    {
        cout << 0;
    }
    else
    {
        cout << sumValue - minValue;
    }
    return 0;
}