#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int N, M, R, t;
ll answer;
vector<vector<int>> graph;
vector<bool> isVisited;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> R;

    isVisited = vector<bool>(N + 1);
    graph = vector<vector<int>>(N + 1, vector<int>());

    while (M--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }
}

void dfs(int curNode, ll depth)
{
    isVisited[curNode] = true;

    answer += depth * ++t;

    for (int nextNode : graph[curNode])
    {
        if (isVisited[nextNode])
        {
            continue;
        }

        dfs(nextNode, depth + 1);
    }
}

int main()
{
    input();
    dfs(R, 0);
    cout << answer;
    return 0;
}