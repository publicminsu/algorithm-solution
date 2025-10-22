#include <iostream>

using namespace std;

int N, M;
int map[301][301];
int dp[301][301];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
        }
    }

    cout << dp[N][M];
    return 0;
}