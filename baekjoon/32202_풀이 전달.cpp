#include <iostream>
using namespace std;
#define MOD 1000000007

int N;
int oneChoice, prevTwo;
int dp[2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    dp[0] = 1;
    dp[1] = 2;

    for (int i = 1; i < N; ++i)
    {
        int prev0 = dp[0];
        int prev1 = dp[1];

        dp[0] = prev1;
        dp[1] = (prev0 + prev1) % MOD;
        dp[1] = (dp[1] * 2) % MOD;
    }

    cout << (dp[0] + dp[1]) % MOD;
    return 0;
}
