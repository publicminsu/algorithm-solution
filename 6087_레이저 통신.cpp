#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;
struct node
{
    int y, x, dy, dx, mirror;
};
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int W, H;
    pair<int, int> start, end;
    cin >> W >> H;
    vector<vector<int>> map(H, vector<int>(W, INT_MAX));
    queue<node> bfs;
    bool init = false;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            char c;
            cin >> c;
            if (c == '.')
                map[i][j] = INT_MAX;
            else if (c == '*')
                map[i][j] = -1;
            else
            {
                if (init)
                {
                    end = {i, j};
                    map[i][j] = INT_MAX;
                }
                else
                {
                    init = true;
                    start = {i, j};
                    map[i][j] = -1;
                }
            }
        }
    }
    bfs.push({start.first, start.second, 0, 0, -1});
    while (!bfs.empty())
    {
        node cur = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; ++i)
        {
            int weight = ((cur.dy == dy[i] && cur.dx == dx[i]) ? 0 : 1);
            node next = {cur.y + dy[i], cur.x + dx[i], dy[i], dx[i], cur.mirror + weight};
            if (next.y < 0 || next.x < 0 || next.y >= H || next.x >= W)
                continue;
            if (next.mirror > map[next.y][next.x])
                continue;
            map[next.y][next.x] = next.mirror;
            bfs.push(next);
        }
    }
    cout << map[end.first][end.second];
    return 0;
}