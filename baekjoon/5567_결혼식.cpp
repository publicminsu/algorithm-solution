#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> graph;
vector<int> dist;
int n, m;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    dist = vector<int>(n + 1, 987654321);
    graph = vector<vector<int>>(n + 1, vector<int>());

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (const int &next : graph[cur])
        {
            int nextDist = dist[cur] + 1;

            if (dist[next] <= nextDist)
            {
                continue;
            }

            dist[next] = nextDist;
            q.push(next);
        }
    }

    int answer = 0;
    for (const int &d : dist)
    {
        if (d > 0 && d < 3)
        {
            ++answer;
        }
    }
    cout << answer;
    return 0;
}