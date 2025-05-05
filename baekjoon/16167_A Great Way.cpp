#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using pii = pair<int, int>;
using piiii = pair<pii, pii>;

int N, R;
vector<vector<pii>> graph;
priority_queue<piiii, vector<piiii>, greater<piiii>> pq;
vector<int> dist;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> R;

    graph = vector<vector<pii>>(N + 1, vector<pii>());
    dist = vector<int>(N + 1, -1);

    while (R--)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;

        int cost = c;

        e -= 10;

        if (e > 0)
        {
            cost += e * d;
        }

        graph[a].push_back({b, cost});
    }
}

void dijkstra()
{
    pq.push({{0, 1}, {0, 1}});

    while (!pq.empty())
    {
        piiii curNode = pq.top();
        pq.pop();
        pii curValue = curNode.first;
        pii curPos = curNode.second;

        int &d = dist[curPos.second];

        if (d != -1)
        {
            continue;
        }

        d = curValue.first;

        if (curPos.second == N)
        {
            cout << d << " " << curValue.second;
            return;
        }

        for (const pii &d : graph[curPos.second])
        {
            piiii nextNode = {{curValue.first + d.second, curValue.second + 1}, {curPos.second, d.first}};

            pq.push(nextNode);
        }
    }

    cout << "It is not a great way.";
}

int main()
{
    input();
    dijkstra();
    return 0;
}