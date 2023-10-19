#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
struct node
{
    int y, x, cnt;
    bool wall;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<vector<bool>>> isVisted = vector<vector<vector<bool>>>(2, vector<vector<bool>>(N, vector<bool>(M)));
    vector<vector<bool>> wall = vector<vector<bool>>(N, vector<bool>(M));
    queue<node> bfs;
    for (int i = 0; i < N; ++i)
    {
        string line;
        cin >> line;
        for (int j = 0; j < M; ++j)
        {
            wall[i][j] = (line[j] == '1' ? true : false);
        }
    }
    bfs.push({0, 0, 1, false});
    while (!bfs.empty())
    {
        node cur = bfs.front();
        if (cur.y == N - 1 && cur.x == M - 1)
        {
            break;
        }
        bfs.pop();
        for (int i = 0; i < 4; ++i)
        {
            node next = {cur.y + dy[i], cur.x + dx[i], cur.cnt + 1, cur.wall};
            if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= M)
                continue;
            if (isVisted[cur.wall][next.y][next.x])
                continue;
            isVisted[cur.wall][next.y][next.x] = true;
            if (wall[next.y][next.x])
            {
                if (!next.wall)
                    bfs.push({next.y, next.x, next.cnt, true});
            }
            else
                bfs.push(next);
        }
    }
    if (bfs.empty())
        cout << -1;
    else
        cout << bfs.front().cnt;
    return 0;
}