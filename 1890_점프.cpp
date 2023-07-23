#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N));
    vector<vector<ll>> dp(N, vector<ll>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];
    dp[0][0] = 1;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            int len = map[i][j];
            if (len == 0)
                continue;
            if (i + len < N)
                dp[i + len][j] += dp[i][j];
            if (j + len < N)
                dp[i][j + len] += dp[i][j];
        }
    cout << dp[N - 1][N - 1];
    return 0;
}