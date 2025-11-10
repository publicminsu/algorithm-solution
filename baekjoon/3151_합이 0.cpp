#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int N;
int A[10000];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
}

void solve()
{
    ll cnt = 0;

    sort(A, A + N);

    for (int i = 0; i < N; ++i)
    {
        const int &a1 = A[i];

        for (int j = i + 1; j < N; ++j)
        {
            const int &a2 = A[j];
            const int target = -(a1 + a2);

            cnt += upper_bound(A + j + 1, A + N, target) - lower_bound(A + j + 1, A + N, target);
        }
    }

    cout << cnt;
}

int main()
{
    input();
    solve();
    return 0;
}