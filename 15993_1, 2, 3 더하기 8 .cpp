#include <iostream>
using namespace std;
long long dp[2][100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int min = 5, T;
    dp[0][1] = 1;
    dp[0][2] = 1;
    dp[1][2] = 1;
    dp[0][3] = 2;
    dp[1][3] = 2;
    dp[0][4] = 3;
    dp[1][4] = 4;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = min; i <= n; ++i)
        {
            dp[0][i] = (dp[1][i - 1] + dp[1][i - 2] + dp[1][i - 3]) % 1000000009;
            dp[1][i] = (dp[0][i - 1] + dp[0][i - 2] + dp[0][i - 3]) % 1000000009;
        }
        cout << dp[0][n] << " " << dp[1][n] << "\n";
        if (n > min)
            min = n;
    }
    return 0;
}