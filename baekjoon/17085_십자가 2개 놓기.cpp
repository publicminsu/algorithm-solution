#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> pos;
vector<vector<bool>> map;
int N, M, ret = 0;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

bool canCross(int y, int x, int len)
{
    for (int i = len; i >= 0; --i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int ny = y + dy[j] * i, nx = x + dx[j] * i;
            if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx])
                return false;
        }
    }
    return true;
}
void buildCross(int y, int x, int len, bool isBuild)
{
    for (int i = len; i >= 0; --i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int ny = y + dy[j] * i, nx = x + dx[j] * i;
            map[ny][nx] = isBuild;
        }
    }
}
void dfs(int idx, int depth, int multi)
{
    if (depth == 2)
    {
        ret = multi > ret ? multi : ret;
        return;
    }
    for (int i = idx; i < pos.size(); ++i)
    {
        pii p = pos[i];
        int y = p.first, x = p.second;
        for (int len = 0; len < 8; ++len)
        {
            if (!canCross(y, x, len))
                break;
            buildCross(y, x, len, true);
            dfs(i + 1, depth + 1, multi * (1 + len * 4));
            buildCross(y, x, len, false);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    map = vector<vector<bool>>(N, vector<bool>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            char c;
            cin >> c;
            if (c == '.')
                map[i][j] = true;
            else
                pos.push_back({i, j});
        }
    dfs(0, 0, 1);
    cout << ret;
    return 0;
}