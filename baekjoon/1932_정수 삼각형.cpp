#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, ret = 0;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
        {
            cin >> dp[i][j];
            dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    for (int i = 1; i <= n; ++i)
        ret = max(ret, dp[n][i]);
    cout << ret;
    return 0;
}