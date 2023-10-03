#include <iostream>
#include <vector>
using namespace std;
int N, K, ret;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    vector<vector<int>> dp(K + 1, vector<int>(N));
    vector<int> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];
    dp[0][0] = !(S[0] % 2);
    ret = max(ret, dp[0][0]);
    for (int i = 1; i < N; ++i)
        if (S[i] % 2) // 짝수인가
            for (int j = 1; j <= K; ++j)
                dp[j][i] = dp[j - 1][i - 1];
        else
            for (int j = 0; j <= K; ++j)
            {
                dp[j][i] = dp[j][i - 1] + 1;
                ret = max(ret, dp[j][i]);
            }
    cout << ret;
    return 0;
}