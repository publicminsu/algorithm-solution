#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[501][501];
int prefix[502];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int K;
        cin >> K;
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < K; ++i)
        {
            int n;
            cin >> n;
            prefix[i + 1] = n;
            dp[i][i] = 0;
        }
        for (int i = 2; i <= K; ++i)
        {
            prefix[i] += prefix[i - 1];
        }
        for (int i = 1; i < K; ++i) // 범위
        {
            for (int j = 0; j < K - i; ++j) // 시작점
            {
                int preSum = prefix[j + i + 1] - prefix[j];
                for (int k = 0; k < i; ++k) // 범위 안에서의 여러 선택
                {
                    dp[j][j + i] = min(dp[j][j + i], dp[j][j + k] + dp[j + k + 1][j + i]);
                }
                dp[j][j + i] += preSum;
            }
        }
        cout << dp[0][K - 1] << "\n";
    }
    return 0;
}