#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> dp(N + 1, vector<int>(100));
    vector<int> hp(N + 1), happy(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> hp[i];
    for (int i = 1; i <= N; ++i)
        cin >> happy[i];
    for (int i = 1; i <= N; ++i)
    {
        int _hp = hp[i], _happy = happy[i];
        for (int j = 1; j < _hp; ++j)
        {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = _hp; j < 100; ++j)
        {
            int nextVal = dp[i - 1][j - _hp] + _happy;
            dp[i][j] = nextVal > dp[i - 1][j] ? nextVal : dp[i - 1][j];
        }
    }
    cout << dp[N][99];
    return 0;
}