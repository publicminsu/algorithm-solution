#include <iostream>
#include <cstring>
using namespace std;
#define MOD 1000007
using ll = long long;
ll dp[201][201];
int w, h, x, y, answer;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> w >> h >> x >> y;
}

void init()
{
    for (int i = 0; i < h; ++i)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < w; ++i)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i < h; ++i)
    {
        for (int j = 1; j < w; ++j)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
}

int main()
{
    input();
    init();
    cout << (dp[y - 1][x - 1] * dp[h - y][w - x]) % MOD;
    return 0;
}