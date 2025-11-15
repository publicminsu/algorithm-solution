#include <iostream>

using namespace std;
using ll = long long;

int N, K;
int costs[2][200001];
ll dp[2][200001];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> costs[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            dp[j][i] = min(dp[j][i - 1], dp[(j + 1) % 2][i - 1] + K) + costs[j][i - 1];
        }
    }

    cout << min(dp[0][N], dp[1][N]);
    return 0;
}
