#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
bool map[5][5], isVisted[5][5], isConn[5][5];
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1}, ret = 0;
vector<pii> pos;
int dfsConn(pii cur)
{
    int cnt = 1;
    for (int i = 0; i < 4; ++i)
    {
        int ny = cur.first + dy[i], nx = cur.second + dx[i];
        if (ny < 0 || nx < 0 || ny > 4 || nx > 4 || !isVisted[ny][nx] || isConn[ny][nx]) // 범위를 벗어나거나 방문하지 않았거나 이미 연결된 곳이면 넘어간다.
            continue;
        isConn[ny][nx] = true;
        cnt += dfsConn({ny, nx});
    }
    return cnt;
}
void dfs(int idx, int depth, int cnt)
{
    if (cnt == 4)
        return;
    if (depth == 7)
    {
        memset(isConn, false, sizeof(isConn));
        int cur = idx - 1;
        pii curNode = pos[cur];
        isConn[curNode.first][curNode.second] = true;
        if (dfsConn(curNode) == 7)
            ++ret;
    }
    for (int i = idx; i < pos.size(); ++i)
    {
        pii p = pos[i];
        int y = p.first, x = p.second, val = !map[y][x] ? 1 : 0;
        isVisted[y][x] = true;
        dfs(i + 1, depth + 1, cnt + val);
        isVisted[y][x] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
        {
            char c;
            cin >> c;
            if (c == 'S')
                map[i][j] = true;
            pos.push_back({i, j});
        }
    dfs(0, 0, 0);
    cout << ret;
    return 0;
}