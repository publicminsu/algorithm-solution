#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, R, cnt = 1;
    cin >> N >> M >> R;
    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> visted(N + 1);
    queue<int> q;
    for (int i = 0, u, v; i < M; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    visted[R] = cnt;
    q.push(R);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        sort(graph[cur].begin(), graph[cur].end(), greater<int>());
        for (int next : graph[cur])
        {
            if (visted[next])
                continue;
            visted[next] = ++cnt;
            q.push(next);
        }
    }
    for (int i = 1; i <= N; ++i)
        cout << visted[i] << "\n";
    return 0;
}