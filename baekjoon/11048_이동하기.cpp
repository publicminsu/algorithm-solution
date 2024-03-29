#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> maze, dp;
int N, M;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    maze = dp = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> maze[i][j];
        }
    }

    // 0인 경우에는 특정 위치를 확인할 수 없다.
    dp[0][0] = maze[0][0];
    for (int i = 1; i < N; ++i)
    {
        dp[i][0] = maze[i][0] + dp[i - 1][0];
    }
    for (int i = 1; i < M; ++i)
    {
        dp[0][i] = maze[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j < M; ++j)
        {
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + maze[i][j]; // (r+1, c), (r, c+1), (r+1, c+1)
        }
    }
    cout << dp[N - 1][M - 1];
    return 0;
}