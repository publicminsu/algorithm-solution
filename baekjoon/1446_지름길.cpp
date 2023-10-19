#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
vector<tiii> shortPaths;
vector<int> dist;
int N, D;
priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijkstra()
{
    pq.push({0, 0});
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        int value = cur.first;
        int idx = cur.second;
        if (dist[idx] <= value)
            continue;
        dist[idx] = value;
        dist[D] = min(dist[D], dist[idx] + (D - idx));
        for (tiii shortPath : shortPaths)
        {
            int start = get<0>(shortPath);
            int end = get<1>(shortPath);
            int len = get<2>(shortPath);
            int nextValue = dist[idx] + (start - idx) + len;
            if (start < idx || dist[end] <= nextValue)
                continue;
            pq.push({nextValue, end});
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> D;
    dist = vector<int>(D + 1, 10001);
    int start, end, len;
    while (N--)
    {
        cin >> start >> end >> len;
        if (end - start < len || end > D)
            continue;
        shortPaths.push_back({start, end, len});
    }
    dijkstra();
    cout << dist[D];
    return 0;
}