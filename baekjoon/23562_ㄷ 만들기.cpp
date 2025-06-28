#include <iostream>
#include <cstring>
using namespace std;

int n, m;
char board[20][20];
bool isUsed[20][20];

struct colorInfo
{
    char color;
    int cost;
};

struct blueprintInfo
{
    int y;
    int x;
    const colorInfo &info;
};

colorInfo blackInfo, whiteInfo;

blueprintInfo blueprints[3][3] = {{{0, 0, blackInfo}, {0, 1, blackInfo}, {0, 2, blackInfo}},
                                  {{1, 0, blackInfo}, {1, 1, whiteInfo}, {1, 2, whiteInfo}},
                                  {{2, 0, blackInfo}, {2, 1, blackInfo}, {2, 2, blackInfo}}};

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    blackInfo.color = '#';
    whiteInfo.color = '.';

    cin >> n >> m >> blackInfo.cost >> whiteInfo.cost;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }
}

int paint(int len, int y, int x, colorInfo info)
{
    int totalCost = 0;

    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            int ny = i + y;
            int nx = j + x;

            isUsed[ny][nx] = true;
            if (board[ny][nx] != info.color)
            {
                totalCost += info.cost;
            }
        }
    }

    return totalCost;
}

int calculateCost(int len, int y, int x)
{
    memset(isUsed, false, sizeof(isUsed));

    int totalCost = 0;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            const blueprintInfo &bp = blueprints[i][j];

            totalCost += paint(len, y + len * bp.y, x + len * bp.x, bp.info);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (isUsed[i][j])
            {
                continue;
            }

            if (board[i][j] != whiteInfo.color)
            {
                totalCost += whiteInfo.cost;
            }
        }
    }

    return totalCost;
}

void solve()
{
    int totalCost = 987654321;

    for (int len = 1; len <= min(n, m) / 3; ++len)
    {
        for (int i = 0; i <= n - 3 * len; ++i)
        {
            for (int j = 0; j <= m - 3 * len; ++j)
            {
                totalCost = min(totalCost, calculateCost(len, i, j));
            }
        }
    }

    cout << totalCost;
}

int main()
{
    input();
    solve();
    return 0;
}