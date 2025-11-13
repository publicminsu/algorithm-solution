#include <iostream>
using namespace std;

int N, K;
int energies[21][2];
int dp[21][2];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cin >> energies[i][j];
        }
    }

    cin >> K;
}

void solve()
{
    for (int i = 1; i < N; ++i)
    {
        dp[i][0] = dp[i - 1][0] + energies[i - 1][0];
        dp[i][1] = dp[i - 1][1] + energies[i - 1][0];

        if (i >= 2)
        {
            dp[i][0] = min(dp[i][0], dp[i - 2][0] + energies[i - 2][1]);
            dp[i][1] = min(dp[i][1], dp[i - 2][1] + energies[i - 2][1]);
        }

        if (i >= 3)
        {
            dp[i][1] = min(dp[i][1], dp[i - 3][0] + K);
        }
    }

    cout << min(dp[N - 1][0], dp[N - 1][1]);
}

int main()
{
    input();
    solve();
    return 0;
}