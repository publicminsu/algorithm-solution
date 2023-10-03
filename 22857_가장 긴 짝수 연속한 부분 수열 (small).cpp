#include <iostream>
#include <vector>
using namespace std;
int N, K, ret, num;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    vector<vector<int>> dp(K + 1, vector<int>(N));
    cin >> num;
    dp[0][0] = !(num % 2);
    ret = max(ret, dp[0][0]);
    for (int i = 1; i < N; ++i)
    {
        cin >> num;
        if (num % 2) // 짝수인가
            for (int j = 1; j <= K; ++j)
                dp[j][i] = dp[j - 1][i - 1];
        else
            for (int j = 0; j <= K; ++j)
            {
                dp[j][i] = dp[j][i - 1] + 1;
                ret = max(ret, dp[j][i]);
            }
    }
    cout << ret;
    return 0;
}