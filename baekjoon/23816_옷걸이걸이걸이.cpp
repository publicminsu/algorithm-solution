#include <iostream>
using namespace std;

int N, M;
int hangerCount[] = {1, 3, 7, 15};
int hangerValue[] = {1, 2, 4, 0};
int dp[5001][10001];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    dp[0][0] = 1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            const int &dpValue = dp[i][j];

            if (!dpValue)
            {
                continue;
            }

            for (int k = 0; k <= 3; ++k)
            {
                int nextIndex = j + hangerCount[k];

                if (nextIndex > M)
                {
                    continue;
                }

                int &nextDPValue = dp[i + 1][nextIndex];

                nextDPValue = max(nextDPValue, dpValue + hangerValue[k]);
            }
        }
    }

    int answer = -1;

    for (int i = 1; i <= N; ++i)
    {
        const int &dpValue = dp[i][M];

        if (dpValue)
        {
            answer = max(answer, dpValue - 1);
        }
    }

    cout << answer;
    return 0;
}