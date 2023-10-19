#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int L, W, ret = 0;
    cin >> L >> W;
    vector<vector<char>> map(L, vector<char>(W));
    vector<vector<bool>> visted;
    queue<pair<int, pair<int, int>>> bfs;
    for (int i = 0; i < L; ++i)
        for (int j = 0; j < W; ++j)
            cin >> map[i][j];
    for (int i = 0; i < L; ++i)
        for (int j = 0; j < W; ++j)
        {
            if (map[i][j] == 'W')
                continue;
            visted = vector<vector<bool>>(L, vector<bool>(W));
            bfs.push({0, {i, j}});
            visted[i][j] = true;
            while (!bfs.empty())
            {
                auto cur = bfs.front();
                bfs.pop();
                for (int i = 0; i < 4; ++i)
                {
                    pair<int, pair<int, int>> next = {cur.first + 1, {cur.second.first + dy[i], cur.second.second + dx[i]}};
                    if (next.second.first < 0 || next.second.second < 0 || next.second.first >= L || next.second.second >= W)
                        continue;
                    if (visted[next.second.first][next.second.second] || map[next.second.first][next.second.second] == 'W')
                        continue;
                    visted[next.second.first][next.second.second] = true;
                    ret = ret > next.first ? ret : next.first;
                    bfs.push(next);
                }
            }
        }
    cout << ret;
}