#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    int y, x;
};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1}, dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, ret = 0;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(M));
    queue<node> q;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> graph[i][j];
            if (graph[i][j])
                q.push({i, j});
        }
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M || graph[ny][nx])
                continue;
            graph[ny][nx] = graph[cur.y][cur.x] + 1;
            ret = max(graph[ny][nx], ret);
            q.push({ny, nx});
        }
    }
    cout << ret - 1;
    return 0;
}