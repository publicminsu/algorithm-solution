#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, R, u, v;
    cin >> N >> M >> R;
    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> depth(N + 1, -1);
    while (M--)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int> q;
    q.push(R);
    depth[R] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur])
        {
            if (depth[next] != -1)
                continue;
            depth[next] = depth[cur] + 1;
            q.push(next);
        }
    }
    for (int i = 1; i <= N; ++i)
        cout << depth[i] << "\n";
    return 0;
}