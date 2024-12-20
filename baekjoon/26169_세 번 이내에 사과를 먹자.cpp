#include <iostream>
using namespace std;
int r, c;
int map[5][5];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> map[i][j];
        }
    }

    cin >> r >> c;
}

bool dfs(int y, int x, int depth, int cnt)
{
    if (depth > 3)
    {
        return false;
    }

    if (cnt >= 2)
    {
        return true;
    }

    for (int i = 0; i < 4; ++i)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
        {
            continue;
        }

        if (map[ny][nx] == -1)
        {
            continue;
        }

        int value = map[ny][nx];

        map[ny][nx] = -1;

        if (dfs(ny, nx, depth + 1, cnt + value))
        {
            return true;
        }

        map[ny][nx] = value;
    }

    return false;
}

int main()
{
    input();
    map[r][c] = -1;
    cout << dfs(r, c, 0, 0);
    return 0;
}