#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> prices(N + 1), dp(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> prices[i];
    for (int i = 1; i <= N; ++i)
    {
        dp[i] = prices[i];
        for (int j = (i + 1) / 2; j < i; ++j)
        {
            int price = dp[j] + prices[i - j];
            dp[i] = price > dp[i] ? price : dp[i];
        }
    }
    cout << dp[N];
    return 0;
}