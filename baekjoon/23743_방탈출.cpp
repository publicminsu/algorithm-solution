#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M;
int exitCost[200001];
vector<pii> graph[200001];
bool isVisited[200001];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    while (M--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    for (int i = 1; i <= N; ++i)
    {
        int t;
        cin >> t;
        graph[0].push_back({t, i});
    }
}

void solve()
{
    int sum = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        pii curNode = pq.top();
        pq.pop();
        int nextIdx = curNode.second;

        if (isVisited[nextIdx])
        {
            continue;
        }

        isVisited[nextIdx] = true;
        sum += curNode.first;

        for (const pii &nextNode : graph[nextIdx])
        {
            pq.push(nextNode);
        }
    }

    cout << sum;
}

int main()
{
    input();
    solve();
    return 0;
}