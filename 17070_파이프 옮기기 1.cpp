#include <iostream>
#include <vector>
using namespace std;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    vector<vector<short>> map(N, vector<short>(N));
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(3)));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];
    dp[0][1][0] = 1;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (j + 1 < N && map[i][j + 1] != 1)
            {
                dp[i][j + 1][0] += dp[i][j][0];
                dp[i][j + 1][0] += dp[i][j][1];
            }
            if (i + 1 < N && map[i + 1][j] != 1)
            {
                dp[i + 1][j][2] += dp[i][j][1];
                dp[i + 1][j][2] += dp[i][j][2];
            }
            if (i + 1 < N && j + 1 < N && !map[i + 1][j] && !map[i][j + 1] && !map[i + 1][j + 1])
            {
                dp[i + 1][j + 1][1] += dp[i][j][0];
                dp[i + 1][j + 1][1] += dp[i][j][1];
                dp[i + 1][j + 1][1] += dp[i][j][2];
            }
        }
    cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
    return 0;
}