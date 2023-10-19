#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pos;
string line;
int H, W, dy[] = {0, 0, 1, -1, 1, 1, -1, -1}, dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
vector<vector<int>> map;
queue<pos> target, buffer;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> H >> W;
    map = vector<vector<int>>(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
    {
        cin >> line;
        for (int j = 0; j < W; ++j)
            if (line[j] == '.')
            {
                map[i][j] = 0;
                target.push({i, j});
            }
            else
                map[i][j] = line[j] - '0';
    }
}
bool isOut(int y, int x)
{
    return y < 0 || x < 0 || y >= H || x >= W;
}
int solve()
{
    int ret = 0;
    while (true)
    {
        while (!target.empty())
        {
            pos cur = target.front();
            target.pop();
            for (int i = 0; i < 8; ++i)
            {
                int ny = cur.first + dy[i], nx = cur.second + dx[i];
                if (isOut(ny, nx) || !map[ny][nx])
                    continue;
                if (--map[ny][nx] == 0)
                    buffer.push({ny, nx});
            }
        }
        if (buffer.empty())
            return ret;
        buffer.swap(target);
        ++ret;
    }
}
int main()
{
    input();
    cout << solve();
    return 0;
}