#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<vector<int>> map, dp;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    map = dp = vector<vector<int>>(N, vector<int>(M, N * M + 1));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            for (int k = 1; k <= map[i][j]; ++k)
            {
                if (i + k < N)
                    dp[i + k][j] = min(dp[i + k][j], dp[i][j] + 1);
                if (j + k < M)
                    dp[i][j + k] = min(dp[i][j + k], dp[i][j] + 1);
            }
    cout << dp[N - 1][M - 1];
    return 0;
}