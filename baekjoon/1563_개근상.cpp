#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000
int N, answer;
int dp[2][3][1001];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    dp[0][0][0] = dp[0][1][0] = dp[1][0][0] = 1;

    for (int i = 1; i < N; ++i)
    {
        dp[0][0][i] = (dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1]) % MOD;
        dp[0][1][i] = dp[0][0][i - 1];
        dp[0][2][i] = dp[0][1][i - 1];

        dp[1][0][i] = (dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1] + dp[1][0][i - 1] + dp[1][1][i - 1] + dp[1][2][i - 1]) % MOD;
        dp[1][1][i] = dp[1][0][i - 1];
        dp[1][2][i] = dp[1][1][i - 1];
    }

    for (int j = 0; j < 2; ++j)
    {
        for (int k = 0; k < 3; ++k)
        {
            answer = (answer + dp[j][k][N - 1]) % MOD;
        }
    }

    cout << answer;
    return 0;
}