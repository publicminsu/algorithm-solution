#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, R, u, v;
vector<vector<int>> graph;
vector<int> order;
int cnt = 0;
void init()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> R;

    graph = vector<vector<int>>(N + 1, vector<int>());
    order = vector<int>(N + 1);

    while (M--)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }
}
void dfs(int cur)
{
    order[cur] = ++cnt;

    for (int next : graph[cur])
    {
        if (order[next])
        {
            continue;
        }

        dfs(next);
    }
}
int main()
{
    init();
    dfs(R);
    for (int i = 1; i <= N; ++i)
    {
        cout << order[i] << "\n";
    }
    return 0;
}