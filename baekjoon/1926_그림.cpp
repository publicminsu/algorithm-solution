#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, artMax = 0, artCnt = 0;
    cin >> n >> m;
    vector<vector<bool>> map(n, vector<bool>(m));
    queue<pair<int, int>> bfs;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int k;
            cin >> k;
            map[i][j] = k;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!map[i][j])
                continue;
            int cnt = 0;
            ++artCnt;
            bfs.push({i, j});
            while (!bfs.empty())
            {
                auto cur = bfs.front();
                bfs.pop();
                if (!map[cur.first][cur.second])
                    continue;
                map[cur.first][cur.second] = false;
                ++cnt;
                for (int k = 0; k < 4; ++k)
                {
                    pair<int, int> next = {cur.first + dy[k], cur.second + dx[k]};
                    if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m)
                        continue;
                    bfs.push(next);
                }
            }
            if (cnt > artMax)
                artMax = cnt;
        }
    }
    cout << artCnt << "\n"
         << artMax;
    return 0;
}