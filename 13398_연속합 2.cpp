#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<vector<int>> dp;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, num, ret;
    cin >> n;
    v = vector<int>(n);
    dp = vector<vector<int>>(2, vector<int>(n));
    cin >> v[0];
    dp[0][0] = v[0];
    ret = dp[0][0];
    for (int i = 1; i < n; ++i)
    {
        cin >> v[i];
        dp[0][i] = max(v[i], v[i] + dp[0][i - 1]);
        if (i >= 1)
        {
            dp[1][i] = dp[1][i - 1];
            if (i > 1)
                dp[1][i] = max(dp[1][i], dp[0][i - 2]);
            dp[1][i] += v[i];
        }
        ret = max(max(dp[0][i], dp[1][i]), ret);
    }
    cout << ret;
    return 0;
}