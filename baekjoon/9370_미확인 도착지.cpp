#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int tc, n, m, t, s, g, h, dist[2001][2], dest[101];
vector<pii> graph[2001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
void findDist(int start, bool isSecond)
{
    dist[start][isSecond] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        int curVal = cur.first;
        int curIdx = cur.second;
        for (pii next : graph[curIdx])
        {
            int nextIdx = next.first;
            int nextVal = next.second + curVal;
            if (dist[nextIdx][isSecond] <= nextVal)
                continue;
            dist[nextIdx][isSecond] = nextVal;
            pq.push({nextVal, nextIdx});
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> tc;
    while (tc--)
    {
        memset(dist, 0x3f3f3f3f, sizeof(dist));
        for (int i = 1; i <= n; ++i)
            graph[i].clear();
        cin >> n >> m >> t >> s >> g >> h;
        for (int i = 0, a, b, d; i < m; ++i)
        {
            cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }
        for (int i = 0; i < t; ++i)
            cin >> dest[i];
        sort(dest, dest + t);
        findDist(s, false);
        int target, other, otherWayDist;
        if (dist[g][false] < dist[h][false])
            target = g, other = h;
        else
            target = h, other = g;
        otherWayDist = dist[target][false];
        for (pii next : graph[target])
            if (next.first == other)
            {
                otherWayDist += next.second;
                break;
            }
        findDist(other, true);
        for (int i = 0; i < t; ++i)
            if (dist[dest[i]][false] == otherWayDist + dist[dest[i]][true])
                cout << dest[i] << " ";
        cout << "\n";
    }
    return 0;
}