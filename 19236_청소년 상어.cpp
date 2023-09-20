#include <iostream>
#include <vector>
using namespace std;
struct fish
{
    int dir, y, x;
    bool isDie;
};
struct shark
{
    int dir, y, x, sum;
};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1}, ret;
void input(vector<fish> &fishs, vector<vector<int>> &map)
{
    int a, b;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            cin >> a >> b;
            fishs[a] = {b - 1, i, j, false};
            map[i][j] = a;
        }
}
int nextDir(shark &s, fish cur)
{
    while (true)
    {
        int ny = cur.y + dy[cur.dir];
        int nx = cur.x + dx[cur.dir];
        if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4 || (s.y == ny && s.x == nx))
            cur.dir = (cur.dir + 1) % 8;
        else
            return cur.dir;
    }
}
void eat(shark &s, vector<fish> &fishs, vector<vector<int>> &map)
{
    int fishIdx = map[s.y][s.x];
    s.sum += fishIdx;
    s.dir = fishs[fishIdx].dir;
    fishs[fishIdx].isDie = true;
    map[s.y][s.x] = 0;
}
void dfs(shark s, vector<fish> fishs, vector<vector<int>> map)
{
    eat(s, fishs, map);
    ret = max(s.sum, ret);
    for (int i = 1; i <= 16; ++i)
    {
        fish cur = fishs[i];
        if (cur.isDie)
            continue;
        int cy = cur.y;
        int cx = cur.x;
        int nd = nextDir(s, cur);
        int ny = cy + dy[nd];
        int nx = cx + dx[nd];
        int otherIdx = map[ny][nx];
        fishs[otherIdx].y = cy;
        fishs[otherIdx].x = cx;
        fishs[i].y = ny;
        fishs[i].x = nx;
        fishs[i].dir = nd;
        map[cy][cx] = otherIdx;
        map[ny][nx] = i;
    }
    for (int i = 1; i < 4; ++i)
    {
        int ny = s.y + dy[s.dir] * i;
        int nx = s.x + dx[s.dir] * i;
        if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)
            break;
        else if (map[ny][nx] == 0)
            continue;
        shark n = s;
        n.y = ny;
        n.x = nx;
        dfs(n, fishs, map);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    vector<fish> fishs(17);
    vector<vector<int>> map(4, vector<int>(4));
    input(fishs, map);
    shark s = {0, 0, 0, 0};
    dfs(s, fishs, map);
    cout << ret;
    return 0;
}