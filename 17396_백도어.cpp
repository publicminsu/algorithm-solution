#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, a, b, t;
    cin >> N >> M;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vector<bool> blocked(N);
    vector<vector<pli>> graph(N, vector<pli>());
    vector<ll> dir(N, 10000000001);
    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        blocked[i] = j;
    }
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> t;
        if ((blocked[a] && a < N - 1) || (blocked[b] && b < N - 1))
            continue;
        graph[a].push_back({t, b});
        graph[b].push_back({t, a});
    }
    dir[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        pli cur = pq.top();
        pq.pop();
        if (dir[cur.second] < cur.first)
            continue;

        for (pli next : graph[cur.second])
        {
            if (dir[next.second] <= dir[cur.second] + next.first)
                continue;
            dir[next.second] = dir[cur.second] + next.first;
            pq.push({dir[next.second], next.second});
        }
    }
    cout << (dir[N - 1] == 10000000001 ? -1 : dir[N - 1]);
    return 0;
}