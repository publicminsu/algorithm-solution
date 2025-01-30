#include <iostream>
using namespace std;

#define INF 987654321

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int map[5][5];
int countMap[5][5];
int r, c, answer = INF;
void dfs(int y, int x, int count);

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

bool isOut(int x)
{
    return x < 0 || x > 4;
}

bool isOut(int y, int x)
{
    return isOut(y) || isOut(x) || map[y][x] == -1;
}

void walk(int y, int x, int dir, int nextCount)
{
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (isOut(ny, nx))
    {
        return;
    }

    if (countMap[ny][nx] && nextCount >= countMap[ny][nx])
    {
        return;
    }

    countMap[ny][nx] = nextCount;

    dfs(ny, nx, nextCount);
}

void run(int y, int x, int dir, int nextCount)
{
    for (int dist = 1; dist < 5; ++dist)
    {
        int ny = y + dy[dir] * dist;
        int nx = x + dx[dir] * dist;

        if (isOut(ny, nx))
        {
            break;
        }

        if (isOut(ny + dy[dir], nx + dx[dir]) || map[ny][nx] == 7)
        {
            if (countMap[ny][nx] && nextCount >= countMap[ny][nx])
            {
                break;
            }

            countMap[ny][nx] = nextCount;
            dfs(ny, nx, nextCount);

            break;
        }
    }
}

void dfs(int y, int x, int count)
{
    if (map[y][x] == 1)
    {
        answer = min(answer, count);
        return;
    }

    int nextCount = count + 1;

    for (int dir = 0; dir < 4; ++dir)
    {
        run(y, x, dir, nextCount);
        walk(y, x, dir, nextCount);
    }
}

int main()
{
    input();
    dfs(r, c, 0);

    if (answer == INF)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
    return 0;
}