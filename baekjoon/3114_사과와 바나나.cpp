#include <iostream>
using namespace std;

#define SIZE 1501

int R, C;
int apples[SIZE][SIZE];
int bananas[SIZE][SIZE];
int dp[SIZE][SIZE];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> R >> C;

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            char type;
            int cnt;

            cin >> type >> cnt;

            if (type == 'A')
            {
                apples[i][j] = cnt;
            }
            else
            {
                bananas[i][j] = cnt;
            }
        }
    }
}

void solve()
{
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            apples[i][j] += apples[i][j - 1];
            bananas[i][j] += bananas[i - 1][j];
        }
    }

    for (int i = 2; i <= R; ++i)
    {
        for (int j = 2; j <= C; ++j)
        {
            int &value = dp[i][j];
            const int &apple = apples[i][j - 1];
            const int &banana = bananas[i - 1][j];

            value = dp[i][j - 1] + banana;
            value = max(value, dp[i - 1][j] + apple);
            value = max(value, dp[i - 1][j - 1] + apple + banana);
        }
    }

    cout << dp[R][C];
}

int main()
{
    input();
    solve();
    return 0;
}