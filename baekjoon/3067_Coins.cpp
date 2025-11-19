#include <iostream>
#include <cstring>

using namespace std;

int T, N, M;
int coins[20];
int dp[10001];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> coins[i];
        }
        cin >> M;

        for (int j = 0; j < N; ++j)
        {
            int coin = coins[j];

            for (int i = coin; i <= M; ++i)
            {
                dp[i] += dp[i - coin];
            }
        }

        cout << dp[M] << "\n";
    }
    return 0;
}