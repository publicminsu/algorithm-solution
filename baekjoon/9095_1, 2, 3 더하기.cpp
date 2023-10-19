#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    vector<int> dp(11);
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 10; ++i)
    {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    while (T--)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}