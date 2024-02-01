#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
#define INF 100000001
vector<vector<pii>> graph;
vector<pii> dist;
int N, robot1, robot2;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> robot1 >> robot2;
    graph = vector<vector<pii>>(N + 1, vector<pii>());
    dist = vector<pii>(N + 1, {INF, 0});

    int a, b, c;
    for (int i = 1; i < N; ++i)
    {
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
}
void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, robot1});
    dist[robot1] = {0, 0};

    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();

        if (dist[cur.second].first > cur.first) // 이미 기록된 값보다 큰 경우
        {
            continue;
        }

        for (pii next : graph[cur.second])
        {
            int nextVal = dist[cur.second].first + next.first;
            if (dist[next.second].first <= nextVal) // 이미 기록된 값과 같거나 큰 경우
            {
                continue;
            }
            dist[next.second] = {nextVal, max(dist[cur.second].second, next.first)};
            pq.push({nextVal, next.second});
        }
    }

    cout << dist[robot2].first - dist[robot2].second;
}
int main()
{
    input();
    dijkstra();
    return 0;
}