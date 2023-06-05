#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int V, E, M, x, S, y, ret = 100000001;
    cin >> V >> E;
    vector<vector<pii>> graph(V + 1, vector<pii>());
    vector<vector<int>> d(2, vector<int>(V + 1, 100000001));
    for (int i = 0, u, v, w; i < E; ++i)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // 맥도날드
    cin >> M >> x;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0, m; i < M; ++i)
    {
        cin >> m;
        d[0][m] = 0;
        pq.push({0, m});
    }
    while (!pq.empty())
    {
        pii curNode = pq.top();
        int cur = curNode.second;
        int val = curNode.first;
        pq.pop();
        if (val > d[0][cur])
            continue;
        for (pii nextNode : graph[cur])
        {
            int next = nextNode.first;
            int nextVal = val + nextNode.second;
            if (nextVal >= d[0][next] || nextVal > x)
                continue;
            d[0][next] = nextVal;
            pq.push({nextVal, next});
        }
    }

    // 스타벅스
    cin >> S >> y;
    for (int i = 0, s; i < S; ++i)
    {
        cin >> s;
        d[1][s] = 0;
        pq.push({0, s});
    }
    while (!pq.empty())
    {
        pii curNode = pq.top();
        int cur = curNode.second;
        int val = curNode.first;
        pq.pop();
        if (val > d[1][cur])
            continue;
        for (pii nextNode : graph[cur])
        {
            int next = nextNode.first;
            int nextVal = val + nextNode.second;
            if (nextVal >= d[1][next] || nextVal > y)
                continue;
            if (d[0][next] != 100000001 && d[0][next] != 0)
            {
                int sum = nextVal + d[0][next];
                ret = sum < ret ? sum : ret;
            }
            d[1][next] = nextVal;
            pq.push({nextVal, next});
        }
    }
    if (ret == 100000001)
        cout << -1;
    else
        cout << ret;
    return 0;
}