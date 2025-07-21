#include <iostream>
using namespace std;

int T, a, b;

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
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        int gcdValue = gcd(a, b);

        cout << a * b / gcdValue << " " << gcdValue << "\n";
    }
    return 0;
}