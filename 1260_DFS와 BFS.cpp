#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> graph;
int N, M, V;
vector<bool> isVisted;
void dfs(int cur)
{
    cout << cur << " ";
    for (int next : graph[cur])
    {
        if (isVisted[next])
            continue;
        isVisted[next] = true;
        dfs(next);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> V;
    graph = vector<vector<int>>(N + 1, vector<int>());
    isVisted = vector<bool>(N + 1);
    queue<int> bfs;
    for (int i = 0; i < M; ++i)
    {
        int p1, p2;
        cin >> p1 >> p2;
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);
    }
    for (int i = 0; i <= N; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    isVisted[V] = true;
    dfs(V);
    cout << "\n";
    fill(isVisted.begin(), isVisted.end(), false);
    isVisted[V] = true;
    bfs.push(V);
    while (!bfs.empty())
    {
        int cur = bfs.front();
        bfs.pop();
        cout << cur << " ";
        for (int next : graph[cur])
        {
            if (isVisted[next])
                continue;
            isVisted[next] = true;
            bfs.push(next);
        }
    }
    return 0;
}