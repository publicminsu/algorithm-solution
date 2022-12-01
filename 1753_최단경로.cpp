#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<pair<int, int>>> vertex; // 번호, 가중치
    vector<int> dis;
    int V, E, start;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 가중치, 번호
    cin >> V >> E >> start;
    --start;
    for (int i = 0; i < V; ++i)
    {
        dis.push_back(INT_MAX);
        vertex.push_back(vector<pair<int, int>>());
    }
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vertex[u - 1].push_back({v - 1, w});
    }
    dis[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        pair<int, int> curNode = pq.top();
        pq.pop();
        if (dis[curNode.second] < curNode.first)
            continue;
        for (int i = 0; i < vertex[curNode.second].size(); ++i)
        {
            pair<int, int> nextNode = vertex[curNode.second][i];
            if (dis[nextNode.first] > curNode.first + nextNode.second)
            {
                dis[nextNode.first] = curNode.first + nextNode.second;
                pq.push({dis[nextNode.first], nextNode.first});
            }
        }
    }
    for (int i = 0; i < V; ++i)
    {
        if (dis[i] == INT_MAX)
            cout << "INF";
        else
            cout << dis[i];
        cout << '\n';
    }
    return 0;
}