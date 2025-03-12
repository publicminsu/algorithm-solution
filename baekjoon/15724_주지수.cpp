#include <iostream>
using namespace std;

int N, M, K;
int x1, y1, x2, y2;
int dp[1025][1025];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> dp[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            dp[i][j] += dp[i][j - 1];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            dp[i][j] += dp[i - 1][j];
        }
    }

    cin >> K;

    while (K--)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        cout << (dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]) << "\n";
    }

    return 0;
}