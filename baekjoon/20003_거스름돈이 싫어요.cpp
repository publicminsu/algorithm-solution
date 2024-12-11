#include <iostream>
using namespace std;
using ll = long long;
int N;
ll lA, lB, rA, rB;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> lA >> lB;

    ll g = gcd(lA, lB);

    lA /= g;
    lB /= g;

    while (--N)
    {
        cin >> rA >> rB;

        ll g = gcd(rA, rB);

        rA /= g;
        rB /= g;

        lA = gcd(lA, rA);
        lB = lcm(lB, rB);
    }

    cout << lA << " " << lB;
    return 0;
}