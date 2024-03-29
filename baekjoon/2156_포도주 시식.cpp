#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n + 1), wine(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> wine[i];
    dp[0] = wine[0];
    dp[1] = wine[1];
    dp[2] = wine[2] + wine[1];
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = max(max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]), dp[i - 1]);
    }
    cout << dp[n];
}