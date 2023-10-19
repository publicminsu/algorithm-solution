#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M));
    queue<pair<int, int>> bfs;
    for (int i = 0; i < N; ++i)
    {
        string k;
        cin >> k;
        for (int j = 0; j < M; ++j)
        {
            map[i][j] = k[j] - '0';
        }
    }
    bfs.push({0, 0});
    while (!bfs.empty())
    {
        auto cur = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= M)
                continue;
            if (!map[next.first][next.second] || map[next.first][next.second] > 1)
                continue;
            map[next.first][next.second] = map[cur.first][cur.second] + 1;
            bfs.push(next);
        }
    }
    cout << map[N - 1][M - 1];
    return 0;
}