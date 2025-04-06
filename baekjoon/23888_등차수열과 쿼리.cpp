#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
ll a, d, q, cmd, l, r;
int gcd;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> a >> d >> q;
    gcd = __gcd(a, d);

    while (q--)
    {
        cin >> cmd >> l >> r;

        ll firstValue = a + d * (l - 1);

        if (cmd == 1)
        {
            ll n = r - l + 1;
            cout << (2LL * firstValue + (n - 1) * d) * n / 2;
        }
        else
        {
            if (l == r)
            {
                cout << firstValue;
            }
            else
            {
                cout << gcd;
            }
        }
        cout << "\n";
    }
    return 0;
}