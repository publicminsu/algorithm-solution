#include <iostream>
#include <vector>
using namespace std;
#define INF 101
vector<int> dp;
int N, K, C;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;

    dp = vector<int>(K + 1, INF);

    dp[0] = 0;

    while (N--)
    {
        cin >> C;

        for (int i = K - C; i >= 0; --i)
        {
            if (dp[i] != INF)
            {
                dp[i + C] = min(dp[i + C], dp[i] + 1);
            }
        }
    }

    if (dp[K] == INF)
    {
        cout << -1;
    }
    else
    {
        cout << dp[K];
    }
    return 0;
}