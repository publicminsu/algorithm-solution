#include <iostream>
#include <cstring>
using namespace std;
int n, m, c, p;
int dp[10001];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (true)
    {
        float temp;
        cin >> n >> temp;
        m = temp * 100 + 0.5f;

        if (n == 0)
        {
            break;
        }

        memset(dp, 0, sizeof(dp));

        while (n--)
        {
            cin >> c >> temp;
            p = temp * 100 + 0.5f;

            for (int i = p; i <= m; ++i)
            {
                dp[i] = max(dp[i], dp[i - p] + c);
            }
        }

        cout << dp[m] << "\n";
    }
    return 0;
}