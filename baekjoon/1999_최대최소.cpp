#include <iostream>
using namespace std;
int dp[251][251][3]; // 기본(답변으로 재활용), 가로 최소, 가로 최대
int N, B, K;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> B >> K;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> dp[i][j][0];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= N - B; ++j)
        {
            dp[i][j][2] = dp[i][j][1] = dp[i][j][0];

            for (int k = 1; k < B; ++k)
            {
                dp[i][j][1] = min(dp[i][j][1], dp[i][j + k][0]);
                dp[i][j][2] = max(dp[i][j][2], dp[i][j + k][0]);
            }
        }
    }

    for (int i = 0; i <= N - B; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int minNum = dp[i][j][1];
            int maxNum = dp[i][j][2];

            for (int k = 1; k < B; ++k)
            {
                minNum = min(minNum, dp[i + k][j][1]);
                maxNum = max(maxNum, dp[i + k][j][2]);
            }

            dp[i][j][0] = maxNum - minNum;
        }
    }

    while (K--)
    {
        int i, j;
        cin >> i >> j;
        --i, --j;

        cout << dp[i][j][0] << "\n";
    }
    return 0;
}