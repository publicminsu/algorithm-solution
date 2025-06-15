#include <iostream>

using namespace std;
using ll = long long;

ll N, A, B, C, D, E, F, X;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> A >> B >> C >> D >> E >> F;

    for (ll i = (N / F) * F + 1; i <= N; ++i)
    {
        if (i % A == 0)
        {
            X += i;
        }

        if (i % B == 0)
        {
            X %= i;
        }

        if (i % C == 0)
        {
            X &= i;
        }

        if (i % D == 0)
        {
            X ^= i;
        }

        if (i % E == 0)
        {
            X |= i;
        }
    }

    cout << X;
    return 0;
}