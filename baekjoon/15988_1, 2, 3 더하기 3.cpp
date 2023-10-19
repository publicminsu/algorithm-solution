#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, min = 4;
    cin >> T;
    long long dp[1000001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    while (T--)
    {
        long long n;
        cin >> n;
        for (int i = min; i <= n; ++i)
        {
            dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009;
        }
        cout << dp[n] << "\n";
        if (min < n)
        {
            min = n + 1;
        }
    }
    return 0;
}