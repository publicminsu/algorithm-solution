#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node
{
    int y, x, time;
};

node operator+(const node &a, const node &b)
{
    node ret;
    ret.y = a.y + b.y;
    ret.x = a.x + b.x;
    return ret;
}

int N, M, totalCnt;
bool map[21][21];
bool isVisited[21][21];
node dir[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;

        for (int j = 0; j < M; ++j)
        {
            map[i][j] = str[j] - '0';
            totalCnt += map[i][j];
        }
    }
}

int bfs(node n1, node n2)
{
    memset(isVisited, false, sizeof(isVisited));

    int cnt = 0;

    queue<node> nodes;

    isVisited[n1.y][n1.x] = true;
    isVisited[n2.y][n2.x] = true;

    nodes.push(n1);
    nodes.push(n2);

    while (!nodes.empty())
    {
        node cur = nodes.front();
        nodes.pop();

        for (int i = 0; i < 4; ++i)
        {
            node next = cur + dir[i];

            if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= M)
            {
                continue;
            }

            if (isVisited[next.y][next.x])
            {
                continue;
            }

            isVisited[next.y][next.x] = true;

            cnt += map[next.y][next.x];

            next.time = cur.time + 1;

            if (cnt == totalCnt)
            {
                return next.time;
            }

            nodes.push(next);
        }
    }

    return 0;
}

void solve()
{
    int answer = 401;

    for (int i = 0; i < N * M; ++i)
    {
        int iY = i / M;
        int iX = i % M;

        if (map[iY][iX])
        {
            continue;
        }

        node n1 = {iY, iX, 0};

        for (int j = i + 1; j < N * M; ++j)
        {
            int jY = j / M;
            int jX = j % M;

            if (map[jY][jX])
            {
                continue;
            }

            answer = min(answer, bfs(n1, {jY, jX, 0}));
        }
    }

    cout << answer;
}

int main()
{
    input();
    solve();
    return 0;
}