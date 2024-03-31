#include <iostream>
#include <vector>
using namespace std;
vector<int> P, dp;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    P = vector<int>(N);

    for (int &i : P)
    {
        cin >> i;
    }

    dp = vector<int>(N + 1, 10000000);
    dp[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            dp[i] = min(dp[i], dp[i - j - 1] + P[j]);
        }
    }

    cout << dp[N];
    return 0;
}