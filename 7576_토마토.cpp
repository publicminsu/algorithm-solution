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
    int M, N, cnt = 0, day = 0;
    cin >> M >> N;
    queue<pair<int, int>> bfs;
    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            int k;
            cin >> k;
            if (!k)
                ++cnt;
            else if (k == 1)
                bfs.push({i, j});
            map[i][j] = k;
        }

    if (!cnt)
    {
        cout << 0;
        return 0;
    }
    while (!bfs.empty())
    {
        auto cur = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= M)
                continue;
            if (map[next.first][next.second] != 0)
                continue;
            bfs.push(next);
            map[next.first][next.second] = map[cur.first][cur.second] + 1;
            --cnt;
            if (day < map[next.first][next.second])
                day = map[next.first][next.second];
        }
    }
    if (cnt)
        cout << -1;
    else
        cout << day - 1;
    return 0;
}