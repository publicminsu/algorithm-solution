#include <iostream>
#include <queue>
using namespace std;
#define MOD 1000000007
int n;
int dp[1000][1000];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0, j; i < n * n; ++i)
    {
        cin >> j;
    }

    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = dp[0][i] = i + 1;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + 1) % MOD;
        }
    }

    int code1 = (dp[n - 1][n - 1] + 1) % MOD;

    cout << code1 << " " << n * n;
    return 0;
}