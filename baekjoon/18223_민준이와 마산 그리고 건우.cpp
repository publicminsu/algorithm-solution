#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321
using pii = pair<int, int>;
vector<vector<pii>> graph;
vector<int> dist;
int V, E, P;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> V >> E >> P;
    dist = vector<int>(V + 1, INF);
    graph = vector<vector<pii>>(V + 1, vector<pii>());
    for (int i = 0, a, b, c; i < E; ++i)
    {
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
}
void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();

        if (dist[cur.second] < cur.first) // 저장된 현재 거리보다 더 큰 거리라면
        {
            continue;
        }

        for (pii next : graph[cur.second])
        {
            int nextDist = dist[cur.second] + next.first; // 다음 거리

            if (dist[next.second] <= nextDist) // 이미 저장된 다음 거리보다 더 크거나 같으면
            {
                continue;
            }
            dist[next.second] = nextDist;

            pq.push({nextDist, next.second});
        }
    }
}
bool findParent(int cur)
{
    if (P == cur) // 건우가 위치한 정점이라면
    {
        return true;
    }

    for (pii next : graph[cur])
    {
        if (dist[cur] - next.first == dist[next.second] && findParent(next.second)) // 최단 거리였다면 findParent로 확인
        {
            return true;
        }
    }
    return false;
}
int main()
{
    input();
    dijkstra();
    cout << (findParent(V) ? "SAVE HIM" : "GOOD BYE");
    return 0;
}