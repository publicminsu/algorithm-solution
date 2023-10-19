#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int N, M, A, B, C;
vector<vector<pii>> graph;
vector<pii> ret;
vector<int> dist;
priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    dist = vector<int>(N + 1, 100000);
    graph = vector<vector<pii>>(N + 1, vector<pii>());
    while (M--)
    {
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }
    pq.push({0, 0, 1});
    while (!pq.empty())
    {
        tiii curNode = pq.top();
        pq.pop();
        int value = get<0>(curNode);
        int prev = get<1>(curNode);
        int cur = get<2>(curNode);
        if (dist[cur] != 100000)
            continue;
        dist[cur] = value;
        ret.push_back({prev, cur});
        for (pii nextNode : graph[cur])
        {
            int next = nextNode.first;
            int nextValue = nextNode.second;
            if (value + nextValue >= dist[next])
                continue;
            pq.push({value + nextValue, cur, next});
        }
    }
    ret.erase(ret.begin());
    cout << ret.size() << "\n";
    for (pii cur : ret)
        cout << cur.first << " " << cur.second << "\n";
    return 0;
}