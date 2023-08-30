#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define MAX_DIST 800000001
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, bool> tiib;
vector<vector<pii>> graph;
vector<int> foxDist, wolfDist[2];
int N, M, a, b, d, cnt;
priority_queue<pii, vector<pii>, greater<pii>> foxPQ;
priority_queue<tiib, vector<tiib>, greater<tiib>> wolfPQ;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    graph = vector<vector<pii>>(N + 1, vector<pii>());
    foxDist = wolfDist[0] = wolfDist[1] = vector<int>(N + 1, MAX_DIST);
    while (M--)
    {
        cin >> a >> b >> d;
        d <<= 1;
        graph[a].push_back({d, b});
        graph[b].push_back({d, a});
    }
    foxPQ.push({0, 1});
    while (!foxPQ.empty())
    {
        pii cur = foxPQ.top();
        foxPQ.pop();
        if (foxDist[cur.second] != MAX_DIST)
            continue;
        foxDist[cur.second] = cur.first;
        for (pii next : graph[cur.second])
        {
            if (foxDist[next.second] <= next.first + cur.first)
                continue;
            foxPQ.push({next.first + cur.first, next.second});
        }
    }
    wolfPQ.push({0, 1, false});
    while (!wolfPQ.empty())
    {
        tiib cur = wolfPQ.top();
        wolfPQ.pop();
        int idx = get<1>(cur);
        int value = get<0>(cur);
        bool isRun = get<2>(cur);
        if (wolfDist[isRun][idx] != MAX_DIST)
            continue;
        wolfDist[isRun][idx] = value;
        for (pii next : graph[idx])
        {
            int nextValue = (isRun ? next.first << 1 : next.first >> 1) + value;
            if (wolfDist[!isRun][next.second] <= nextValue)
                continue;
            wolfPQ.push({nextValue, next.second, !isRun});
        }
    }
    for (int i = 2; i <= N; ++i)
        if (foxDist[i] < wolfDist[0][i] && foxDist[i] < wolfDist[1][i])
            ++cnt;
    cout << cnt;
    return 0;
}