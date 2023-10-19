#include <iostream>
#include <vector>
using namespace std;
vector<vector<vector<int>>> dp;
int check(int i, int k, int j)
{
    if (k == j)
        return 0;
    return dp[i][k][j];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
    dp[2][1][2] = dp[2][2][1] = 1;
    for (int i = 3; i <= n; ++i) // 초
    {
        for (int j = 1; j <= i; ++j)
        {
            for (int k = 1; k <= i; ++k)
            {
                if (k == j)
                    continue;
                // 밑으로 내려오는 법, 대각으로 내려오는 법
                dp[i][k][j] = (dp[i][k][j] + dp[i - 1][k][j]) % 10007;
                dp[i][k][j] = (dp[i][k][j] + check(i - 1, k - 1, j)) % 10007;
                dp[i][k][j] = (dp[i][k][j] + check(i - 1, k, j - 1)) % 10007;
                dp[i][k][j] = (dp[i][k][j] + check(i - 1, k - 1, j - 1)) % 10007;
            }
        }
    }
    int ret = 0;
    for (int j = 1; j <= n; ++j)
    {
        for (int k = 1; k <= n; ++k)
        {
            ret = (ret + dp[n][j][k]) % 10007;
        }
    }
    cout << ret;
    return 0;
}