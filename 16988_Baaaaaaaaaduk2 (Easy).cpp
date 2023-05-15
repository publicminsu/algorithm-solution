#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, ret = 0;
vector<vector<int>> map;
vector<vector<bool>> visted;
vector<pii> pos;
pii choose[2], d[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool isEmpty(int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + d[i].first, nx = x + d[i].second;
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (!map[ny][nx])
            return true;
    }
    return false;
}
int bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    int cnt = 1;
    bool isCan = true;
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int ny = d[i].first + cur.first, nx = d[i].second + cur.second;
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;
            if (!map[ny][nx]) // 뚫려있다는 뜻이다.
                isCan = false;
            if (visted[ny][nx] || map[ny][nx] != 2)
                continue;
            visted[ny][nx] = true;
            ++cnt;
            q.push({ny, nx});
        }
    }
    if (!isCan)
        cnt = 0;
    return cnt;
}
void dfs(int idx, int depth)
{
    if (depth == 2)
    {
        visted = vector<vector<bool>>(N, vector<bool>(M));
        int cnt = 0;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                int ny = choose[i].first + d[j].first, nx = choose[i].second + d[j].second;
                if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] != 2 || visted[ny][nx] || isEmpty(ny, nx))
                    continue;
                visted[ny][nx] = true;
                cnt += bfs(ny, nx);
            }
        }
        ret = cnt > ret ? cnt : ret;
        return;
    }
    for (int i = idx; i < pos.size(); ++i)
    {
        choose[depth] = pos[i];
        int y = pos[i].first, x = pos[i].second;
        map[y][x] = 1;
        dfs(i + 1, depth + 1);
        map[y][x] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    map = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
            if (!map[i][j])
                pos.push_back({i, j});
        }
    dfs(0, 0);
    cout << ret;
    return 0;
}