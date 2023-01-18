#include <iostream>
#include <algorithm>
using namespace std;
long long dp[2][100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int j = 0; j < 2; ++j)
            for (int i = 0; i < n; ++i)
            {
                cin >> dp[j][i];
            }
        if (n > 1)
        {
            dp[0][1] += dp[1][0];
            dp[1][1] += dp[0][0];
        }
        for (int i = 2; i < n; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                int k = (j + 1) % 2;
                dp[j][i] += max(dp[k][i - 1], dp[k][i - 2]);
            }
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }
    return 0;
}