#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, cnt = 0;
    cin >> N;
    vector<vector<char>> map(N, vector<char>(N));
    vector<vector<bool>> visted(N, vector<bool>(N));
    queue<pair<int, int>> bfs;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            char k;
            cin >> k;
            map[i][j] = k;
        }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (visted[i][j])
                continue;
            char color = map[i][j];
            ++cnt;
            if (map[i][j] == 'G')
            {
                map[i][j] = 'R';
            }
            bfs.push({i, j});
            while (!bfs.empty())
            {
                auto cur = bfs.front();
                bfs.pop();
                for (int k = 0; k < 4; ++k)
                {
                    pair<int, int> next = {cur.first + dy[k], cur.second + dx[k]};
                    if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= N)
                        continue;
                    if (visted[next.first][next.second] || color != map[next.first][next.second])
                        continue;
                    if (map[next.first][next.second] == 'G')
                    {
                        map[next.first][next.second] = 'R';
                    }
                    visted[next.first][next.second] = true;
                    bfs.push(next);
                }
            }
        }
    cout << cnt << " ";
    cnt = 0;
    fill(visted.begin(), visted.end(), vector<bool>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (visted[i][j])
                continue;
            char color = map[i][j];
            ++cnt;
            bfs.push({i, j});
            while (!bfs.empty())
            {
                auto cur = bfs.front();
                bfs.pop();
                for (int k = 0; k < 4; ++k)
                {
                    pair<int, int> next = {cur.first + dy[k], cur.second + dx[k]};
                    if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= N)
                        continue;
                    if (visted[next.first][next.second] || color != map[next.first][next.second])
                        continue;
                    visted[next.first][next.second] = true;
                    bfs.push(next);
                }
            }
        }
    cout << cnt;
    return 0;
}