#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int N, K, L, R, X;
vector<ll> A;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;

    A = vector<ll>(N);

    for (ll &a : A)
    {
        cin >> a;
    }

    sort(A.begin(), A.end());

    while (K--)
    {
        cin >> L >> R >> X;

        --L;

        for (int i = L; i < R; ++i)
        {
            A[i] += X;
        }

        if (X < 0)
        {
            sort(A.begin(), A.begin() + R);
        }
        else
        {
            sort(A.begin() + L, A.end());
        }
    }

    for (const ll &a : A)
    {
        cout << a << " ";
    }
    return 0;
}