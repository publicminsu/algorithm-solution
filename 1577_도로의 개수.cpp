#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1));
    vector<vector<vector<bool>>> block(N + 1, vector<vector<bool>>(M + 1, vector<bool>(2)));
    while (K--)
    {
        int i, j, k, l;
        cin >> i >> j >> k >> l;
        if (i > k) // 위쪽으로 가는 길
            block[k][l][0] = true;
        else if (j > l) // 오른쪽으로 가는 길
            block[k][l][1] = true;
        else if (k > i) // 위쪽으로 가는 길
            block[i][j][0] = true;
        else // 오른쪽으로 가는 길
            block[i][j][1] = true;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        if (block[i - 1][0][0])
            break;
        dp[i][0] = 1;
    }
    for (int i = 1; i <= M; ++i)
    {
        if (block[0][i - 1][1])
            break;
        dp[0][i] = 1;
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (!block[i - 1][j][0])
            {
                dp[i][j] += dp[i - 1][j];
            }
            if (!block[i][j - 1][1])
            {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    cout << dp[N][M];
    return 0;
}