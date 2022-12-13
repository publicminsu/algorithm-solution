#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> dp(k + 1), coins;
    while (n--)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    dp[0] = 1;
    for (int coin : coins)
    {
        for (int i = coin; i <= k; ++i)
        {
            dp[i] += dp[i - coin];
        }
    }
    cout << dp[k];
    return 0;
}