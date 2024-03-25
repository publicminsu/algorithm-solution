#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
#define INF 1e9
vector<vector<pii>> graph;
vector<int> dist;
int N, M, factory1, factory2;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    dist = vector<int>(N + 1, INF);
    graph = vector<vector<pii>>(N + 1, vector<pii>());
    while (M--)
    {
        int A, B, C;
        cin >> A >> B >> C;

        graph[A].push_back({C, B});
        graph[B].push_back({C, A});
    }

    cin >> factory1 >> factory2;
}
void dijkstra()
{
    priority_queue<pii> pq;

    pq.push({INF, factory1});

    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();

        if (dist[cur.second] != INF)
        {
            continue;
        }

        if (cur.second == factory2)
        {
            cout << cur.first;
            return;
        }

        dist[cur.second] = cur.first;

        for (const pii &next : graph[cur.second])
        {

            if (dist[next.second] != INF)
            {
                continue;
            }

            pq.push({min(next.first, cur.first), next.second});
        }
    }
}
int main()
{
    input();
    dijkstra();
    return 0;
}