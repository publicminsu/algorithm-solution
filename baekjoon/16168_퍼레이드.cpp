#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int V, E, odd = 0;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1, vector<int>());
    vector<bool> visted(V + 1);
    for (int i = 0, a, b; i < E; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visted[1] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur])
        {
            if (visted[next])
                continue;
            visted[next] = true;
            q.push(next);
        }
    }
    for (int i = 1; i <= V; ++i)
        if (!visted[i])
        {
            cout << "NO";
            return 0;
        }
    for (int i = 1; i <= V; ++i)
        if (graph[i].size() % 2)
            ++odd;
    if (odd == 0 || odd == 2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}