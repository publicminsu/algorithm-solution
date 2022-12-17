#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> dp(k + 1, 10001);
    dp[0] = 0;
    while (n--)
    {
        int coin;
        cin >> coin;
        for (int i = coin; i <= k; ++i)
        {
            dp[i] = min(dp[i - coin] + 1, dp[i]);
        }
    }
    cout << ((dp[k] == 10001) ? -1 : dp[k]);
    return 0;
}