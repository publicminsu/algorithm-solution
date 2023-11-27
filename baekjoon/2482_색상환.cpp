#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000003
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<vector<int>> dp(K, vector<int>(N));

    for (int i = 0; i < N; ++i)
    {
        dp[0][i] = 1 + i;
    }

    for (int i = 1; i < K; ++i)
    {
        for (int j = i + 2; j < N; ++j)
        {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 2]) % MOD;
        }
    }

    cout << dp[K - 1][N - 1];
    return 0;
}