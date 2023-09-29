#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>> graph;
vector<int> dist;
int N, E;
void dijkstra(int start)
{
    fill(dist.begin(), dist.end(), 1e06);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        if (dist[cur.second] != 1e06)
            continue;
        dist[cur.second] = cur.first;
        for (pii next : graph[cur.second])
        {
            if (dist[next.second] != 1e06)
                continue;
            pq.push({cur.first + next.first, next.second});
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b, c, v1, v2, ret1 = 0, ret2 = 0;
    cin >> N >> E;
    graph = vector<vector<pii>>(N + 1, vector<pii>());
    dist = vector<int>(N + 1);
    while (E--)
    {
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    cin >> v1 >> v2;
    dijkstra(v1);
    if (dist[v2] == 1e06 || dist[N] == 1e06 || dist[1] == 1e06)
    {
        cout << -1;
        return 0;
    }
    ret1 += dist[v2] + dist[1];
    ret2 += dist[v2] + dist[N];
    dijkstra(v2);
    ret1 += dist[N];
    ret2 += dist[1];
    cout << min(ret1, ret2);
    return 0;
}