#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string answer, correct;
int n, m;
vector<vector<int>> dp;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> answer >> correct;
    dp = vector<vector<int>>(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i)
        dp[i][0] = i;
    for (int i = 1; i <= m; ++i)
        dp[0][i] = i;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if ((answer[i] == correct[j]) || (answer[i] == 'i' && (correct[j] == 'j' || correct[j] == 'l')) || (answer[i] == 'v' && correct[j] == 'w'))
                dp[i + 1][j + 1] = dp[i][j];
            else
                dp[i + 1][j + 1] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j])) + 1;
        }
    cout << dp[n][m];
    return 0;
}