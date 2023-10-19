#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define MAXSIZE 1000
struct node
{
    int y, x, cnt, wall;
};
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
bool visted[11][MAXSIZE][MAXSIZE], wall[MAXSIZE][MAXSIZE];
queue<node> bfs;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
        string line;
        cin >> line;
        for (int j = 0; j < M; ++j)
        {
            wall[i][j] = line[j] == '0' ? false : true;
        }
    }
    visted[0][0][0] = true;
    bfs.push({0, 0, 1, 0});
    while (!bfs.empty())
    {
        node cur = bfs.front();
        bfs.pop();
        if (cur.y == N - 1 && cur.x == M - 1)
        {
            cout << cur.cnt;
            return 0;
        }
        for (int i = 0; i < 4; ++i)
        {
            node next = {cur.y + dy[i], cur.x + dx[i], cur.cnt + 1, cur.wall};
            if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= M)
                continue;
            if (wall[next.y][next.x])
            {
                if (next.wall < K && !visted[next.wall + 1][next.y][next.x])
                {
                    visted[next.wall + 1][next.y][next.x] = true;
                    bfs.push({next.y, next.x, next.cnt, next.wall + 1});
                }
            }
            else if (!wall[next.y][next.x] && !visted[next.wall][next.y][next.x])
            {
                visted[next.wall][next.y][next.x] = true;
                bfs.push(next);
            }
        }
    }
    cout << -1;
    return 0;
}