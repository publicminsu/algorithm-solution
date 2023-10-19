#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>> graph;
vector<int> parent, dist;
int n, m, s, e;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int startCity, endCity, value;
    cin >> n >> m;
    graph = vector<vector<pii>>(n + 1, vector<pii>());
    parent = dist = vector<int>(n + 1, -1);
    while (m--)
    {
        cin >> startCity >> endCity >> value;
        graph[startCity].push_back({value, endCity});
    }
    cin >> s >> e;
}
void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        if (dist[cur.second] != -1 && dist[cur.second] < cur.first)
            continue;
        for (pii next : graph[cur.second])
        {
            if (dist[next.second] != -1 && dist[next.second] <= cur.first + next.first)
                continue;
            dist[next.second] = cur.first + next.first;
            parent[next.second] = cur.second;
            pq.push({cur.first + next.first, next.second});
        }
    }
    cout << dist[e] << "\n";
}
void findParent(int cur, int depth)
{
    if (cur == -1)
    {
        cout << depth - 1 << "\n";
        return;
    }
    findParent(parent[cur], depth + 1);
    cout << cur << " ";
}
int main()
{
    input();
    dijkstra();
    findParent(e, 1);
    return 0;
}