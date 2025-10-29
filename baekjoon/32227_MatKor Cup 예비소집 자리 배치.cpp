#include <iostream>
using namespace std;

using ll = long long;

ll N, M;

ll gcd(ll a, ll b)
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
    cin >> N >> M;

    ll gcdValue = gcd(N, M);

    cout << N / gcdValue << "/" << M / gcdValue;
}