#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int map[8][8], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, N, M, ret = 0;
bool visted[8][8];
vector<pair<int, int>> virus, emptySpace;
void bfs()
{
    int cnt = 0;
    memset(visted, false, sizeof(visted));
    queue<pair<int, int>> q;
    for (auto v : virus)
        q.push(v);
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= M)
                continue;
            if (map[next.first][next.second] || visted[next.first][next.second])
                continue;
            visted[next.first][next.second] = true;
            q.push(next);
        }
    }
    for (auto es : emptySpace)
    {
        if (visted[es.first][es.second] || map[es.first][es.second])
            continue;
        ++cnt;
    }
    ret = cnt > ret ? cnt : ret;
}
void dfs(int cnt, int idx)
{
    if (cnt == 3)
    {
        bfs();
        return;
    }
    for (int i = idx; i < emptySpace.size(); ++i)
    {
        pair<int, int> cur = emptySpace[i];
        map[cur.first][cur.second] = 1;
        dfs(cnt + 1, i + 1);
        map[cur.first][cur.second] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
            if (!map[i][j])
                emptySpace.push_back({i, j});
            else if (map[i][j] == 2)
                virus.push_back({i, j});
        }
    dfs(0, 0);
    cout << ret;
    return 0;
}