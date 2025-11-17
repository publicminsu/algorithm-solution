#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct pos
{
    int y, x;

    pos operator+(const pos &other)
    {
        return {y + other.y, x + other.x};
    }
};

int N, M, time;
int cheese[100][100];
int airContactCount[100][100];
pos dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> cheese[i][j];
        }
    }
}

bool bfs()
{
    memset(airContactCount, 0, sizeof(airContactCount));

    queue<pos> q;
    q.push({0, 0});

    while (!q.empty())
    {
        pos curPos = q.front();
        q.pop();

        for (const pos &d : dir)
        {
            pos nextPos = curPos + d;

            if (nextPos.y < 0 || nextPos.x < 0 || nextPos.y >= N || nextPos.x >= M)
            {
                continue;
            }

            ++airContactCount[nextPos.y][nextPos.x];

            if (!cheese[nextPos.y][nextPos.x] && airContactCount[nextPos.y][nextPos.x] == 1)
            {
                q.push(nextPos);
            }
        }
    }

    bool hasMelted = false;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (cheese[i][j] && airContactCount[i][j] >= 2)
            {
                cheese[i][j] = 0;
                hasMelted = true;
            }
        }
    }

    return hasMelted;
}

int main()
{
    input();

    while (bfs())
    {
        ++time;
    }

    cout << time;
    return 0;
}