#include <iostream>
using namespace std;

int N, M;
int nums[1000][1000];
int dp[1000][1000];
int tmp[2][1000];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> nums[i][j];
        }
    }

    dp[0][0] = nums[0][0];
    for (int i = 1; i < M; ++i)
    {
        dp[0][i] = nums[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i < N; ++i)
    {
        // 왼->오
        tmp[0][0] = nums[i][0] + dp[i - 1][0];
        for (int j = 1; j < M; ++j)
        {
            tmp[0][j] = nums[i][j] + max(dp[i - 1][j], tmp[0][j - 1]);
        }

        // 오->왼
        tmp[1][M - 1] = nums[i][M - 1] + dp[i - 1][M - 1];
        for (int j = M - 2; j >= 0; --j)
        {
            tmp[1][j] = nums[i][j] + max(dp[i - 1][j], tmp[1][j + 1]);
        }

        // 최댓값
        for (int j = 0; j < M; ++j)
        {
            dp[i][j] = max(tmp[0][j], tmp[1][j]);
        }
    }

    cout << dp[N - 1][M - 1];
    return 0;
}