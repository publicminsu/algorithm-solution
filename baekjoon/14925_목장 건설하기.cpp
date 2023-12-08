#include <iostream>
#include <vector>
using namespace std;
int M, N, ret;
vector<vector<int>> map, dp;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> M >> N;
    map = dp = vector<vector<int>>(M, vector<int>(N));
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
        }
    }

    dp[0][0] = ret = (map[0][0] == 0) ? 1 : 0; // 첫 칸에 나무나 바위가 있는가?

    for (int i = 1; i < N; ++i) // 가로 확인
    {
        if (map[0][i] != 0)
        {
            continue;
        }
        dp[0][i] = ret = 1;
    }
    for (int i = 1; i < M; ++i) // 세로 확인
    {
        if (map[i][0] != 0)
        {
            continue;
        }
        dp[i][0] = ret = 1;
    }

    for (int i = 1; i < M; ++i)
    {
        for (int j = 1; j < N; ++j)
        {
            if (map[i][j] != 0) // 만약 나무나 바위가 있다면
            {
                continue;
            }
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1; // 위, 왼쪽, 대각선 확인
            ret = max(ret, dp[i][j]);
        }
    }
    cout << ret;
    return 0;
}