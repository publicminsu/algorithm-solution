#include <iostream>
using namespace std;

int d;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> d;
    int gcdValue = gcd(d, 360);

    if (360 % gcdValue)
    {
        cout << -1;
    }
    else
    {
        cout << (360 / gcdValue);
    }
    return 0;
}