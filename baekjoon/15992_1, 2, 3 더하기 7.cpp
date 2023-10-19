#include <iostream>
using namespace std;
long long dp[1001][1001]; // n m
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[1][1] = 1; // 1
    dp[2][1] = 1; // 2
    dp[2][2] = 1; // 1+1
    dp[3][1] = 1; // 3
    dp[3][2] = 2; // 1+2 2+1
    dp[3][3] = 1; // 1+1+1
    int T, min = 4;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = min; i <= n; ++i)
        {
            for (int j = (i - 1) / 3; j <= i; j++)
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % 1000000009;
            }
        }
        cout << dp[n][m] << "\n";
        if (n > min)
            min = n;
    }
    return 0;
}