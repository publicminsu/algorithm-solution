#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, ret = 1000000;
    cin >> N;
    vector<vector<int>> map(N, vector<int>(3)), dp(N, vector<int>(3, 1000000));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> map[i][j];
    for (int i = 0; i < 3; ++i)
        dp[0][i] = map[0][i];
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 1; k <= 2; ++k)
            {
                int l = (j + k) % 3;
                dp[i][j] = min(dp[i][j], dp[i - 1][l]);
            }
            dp[i][j] += map[i][j];
        }
    for (int i = 0; i < 3; ++i)
        ret = min(ret, dp[N - 1][i]);
    cout << ret;
    return 0;
}