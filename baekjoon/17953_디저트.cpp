#include <iostream>
using namespace std;
int N, M;
int dp[100000][10], V[100000][10];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> V[j][i];
        }
    }
}

void solve()
{
    for (int i = 0; i < M; ++i)
    {
        dp[0][i] = V[0][i];
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int v = V[i][j];
            for (int k = 0; k < M; ++k)
            {
                if (j == k)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + v / 2);
                }
                else
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + v);
                }
            }
        }
    }
}

void print()
{
    int answer = 0;
    for (int i = 0; i < M; ++i)
    {
        answer = max(answer, dp[N - 1][i]);
    }
    cout << answer;
}

int main()
{
    input();
    solve();
    print();
    return 0;
}