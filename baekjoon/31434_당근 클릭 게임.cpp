#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;
vector<vector<int>> dp;
int N, K, answer, maxS;
vector<pii> carrots;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    carrots = vector<pii>(N);
    for (pii &carrot : carrots)
    {
        cin >> carrot.first >> carrot.second;
        maxS = max(maxS, carrot.second);
    }
    maxS = maxS * K + 1;
    dp = vector<vector<int>>(K + 1, vector<int>(maxS, -1));
    dp[0][1] = 0;
}
void solve()
{
    for (int i = 0; i <= K; ++i)
    {
        for (int j = 0; j < maxS; ++j)
        {
            answer = max(answer, dp[i][j]);
            if (dp[i][j] == -1 || i + 1 > K) // 도달하지 못했거나, 범위를 벗어난 경우
            {
                continue;
            }

            dp[i + 1][j] = max(dp[i][j] + j, dp[i + 1][j]);
            for (const pii &carrot : carrots)
            {
                dp[i + 1][j + carrot.second] = max(dp[i][j] - carrot.first, dp[i + 1][j + carrot.second]);
            }
        }
    }
    cout << answer;
}
int main()
{
    input();
    solve();
    return 0;
}