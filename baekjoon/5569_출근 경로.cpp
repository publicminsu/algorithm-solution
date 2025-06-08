#include <iostream>

using namespace std;

#define DEFAULT -1
#define MOD 100000

int h, w;

int dp[101][101][2][2];
int dy[] = {1, 0}, dx[] = {0, 1};

int dfs(int y, int x, int dir, bool hasChangedDirection)
{
    if (y > h || x > w)
    {
        return 0;
    }

    if (h == y && w == x)
    {
        return 1;
    }

    int &value = dp[y][x][dir][hasChangedDirection];

    if (value != DEFAULT)
    {
        return value;
    }

    value = 0;

    if (hasChangedDirection)
    {
        int ny = dy[dir] + y;
        int nx = dx[dir] + x;

        value = dfs(ny, nx, dir, false);
    }
    else
    {
        for (int i = 0; i < 2; ++i)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            value = (value + dfs(ny, nx, i, i != dir)) % MOD;
        }
    }

    return value;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> w >> h;

    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                for (int l = 0; l < 2; ++l)
                {
                    dp[i][j][k][l] = DEFAULT;
                }
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < 2; ++i)
    {
        sum = (sum + dfs(1 + dy[i], 1 + dx[i], i, false)) % MOD;
    }

    cout << sum;
    return 0;
}