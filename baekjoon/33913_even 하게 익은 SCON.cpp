#include <iostream>
using namespace std;

using ll = long long;
#define MOD (ll)(1e9 + 7)

int N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    ll even = 24;
    ll odd = 2;

    for (int i = 2; i <= N; ++i)
    {
        ll nextEven = (even * 24 + odd * 2) % MOD;
        ll nextOdd = (odd * 24 + even * 2) % MOD;

        even = nextEven;
        odd = nextOdd;
    }

    cout << even;
}