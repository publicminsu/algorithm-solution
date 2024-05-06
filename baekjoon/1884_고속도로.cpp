#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;
#define INF 987654321
int K, N, R, answer = INF;
vector<vector<int>> dist;
vector<vector<piii>> graph;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> K >> N >> R;

    dist = vector<vector<int>>(N + 1, vector<int>(K + 1, INF));
    graph = vector<vector<piii>>(N + 1, vector<piii>());
    int s, d, l, t;
    while (R--)
    {
        cin >> s >> d >> l >> t;
        graph[s].push_back({l, {d, t}});
    }
}
void dijkstra()
{
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({0, {1, 0}});
    dist[1][0] = 0;

    while (!pq.empty())
    {
        piii cur = pq.top();
        pq.pop();

        const int &curIdx = cur.second.first;
        const int &curLen = cur.first;
        const int &curCost = cur.second.second;

        if (dist[curIdx][curCost] < curLen)
        {
            continue;
        }

        if (curIdx == N)
        {
            answer = min(answer, curLen);
            return;
        }

        for (piii node : graph[curIdx])
        {
            const int &nextIdx = node.second.first;
            int nextCost = curCost + node.second.second;
            int nextLen = curLen + node.first;

            if (nextCost > K || dist[nextIdx][nextCost] <= nextLen)
            {
                continue;
            }
            dist[nextIdx][nextCost] = nextLen;

            piii next = {nextLen, {nextIdx, nextCost}};

            pq.push(next);
        }
    }
}
int main()
{
    input();
    dijkstra();
    cout << (answer == INF ? -1 : answer);
    return 0;
}