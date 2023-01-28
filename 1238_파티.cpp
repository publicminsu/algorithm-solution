#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<vector<pair<int, int>>>> map;
vector<int> townDist, dist;
int N, M, X;
void Dijkstra(int i, int arrow)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist = vector<int>(N + 1, INT_MAX);
    pq.push({0, i});
    dist[i] = 0;
    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (dist[cur.second] < cur.first)
            continue;
        for (pair<int, int> j : map[arrow][cur.second])
        {
            if (dist[j.second] > dist[cur.second] + j.first)
            {
                dist[j.second] = dist[cur.second] + j.first;
                pq.push({dist[j.second], j.second});
            }
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        townDist[i] += dist[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> X;
    int maxSum = 0;
    map = vector<vector<vector<pair<int, int>>>>(2, vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>()));
    townDist = vector<int>(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int start, end, time;
        cin >> start >> end >> time;
        map[0][start].push_back({time, end});
        map[1][end].push_back({time, start});
    }
    Dijkstra(X, 0);
    Dijkstra(X, 1);
    for (int i = 1; i <= N; ++i)
    {
        maxSum = max(maxSum, townDist[i]);
    }
    cout << maxSum;
    return 0;
}