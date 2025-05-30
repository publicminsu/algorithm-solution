#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int N, Q, X;
ll P[100000], prefix[100000];
ll answer;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;

    for (int i = 0; i < N; ++i)
    {
        cin >> P[i];
    }

    sort(P, P + N);

    prefix[0] = P[0];

    for (int i = 1; i < N; ++i)
    {
        prefix[i] = P[i] + prefix[i - 1];
    }

    while (Q--)
    {
        cin >> X;

        auto iter = lower_bound(P, P + N, X);

        ll idx = iter - P;

        answer = 0;

        ll leftPrefix = idx - 1 >= 0 ? prefix[idx - 1] : 0;

        answer = idx * X - leftPrefix;
        answer += prefix[N - 1] - leftPrefix - X * (N - idx);

        cout << answer << "\n";
    }
    return 0;
}