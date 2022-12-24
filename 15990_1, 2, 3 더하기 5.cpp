#include <iostream>
using namespace std;
long long dp[3][100001];
int dx[] = {1, 2, 3};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[0][1] = dp[1][2] = dp[0][3] = dp[1][3] = dp[2][3] = 1;
    int min = 4, T;
    cin >> T;
    while (T--)
    {
        int n;
        long long sum = 0;
        cin >> n;
        for (int i = min; i <= n; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                int a = (j + 1) % 3, b = (j + 2) % 3;
                dp[j][i] = (dp[a][i - dx[j]] + dp[b][i - dx[j]]) % 1000000009;
            }
        }
        for (int i = 0; i < 3; ++i)
        {
            sum += dp[i][n];
        }
        sum %= 1000000009;
        cout << sum << "\n";
        if (min < n)
        {
            min = n;
        }
    }

    return 0;
}