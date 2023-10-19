#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, X, Y, K;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N + 1, vector<pair<int, int>>());
    vector<vector<int>> cost(N + 1, vector<int>(N + 1));
    vector<int> inDegree(N + 1);
    queue<int> q;
    bool isMid;
    while (M--)
    {
        cin >> X >> Y >> K;
        ++inDegree[X];
        graph[Y].push_back({X, K});
    }
    for (int i = 1; i <= N; ++i)
    {
        if (!inDegree[i] && !graph[i].empty())
            q.push(i);
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        isMid = false;
        for (int i = 1; i <= N - 1; ++i)
            if (cost[cur][i])
            {
                isMid = true;
                break;
            }
        for (auto next : graph[cur])
        {
            if (isMid)
                for (int i = 1; i <= N; ++i)
                {
                    cost[next.first][i] += cost[cur][i] * next.second;
                }
            else
            {
                cost[next.first][cur] = next.second;
            }
            if (!(--inDegree[next.first]))
            {
                q.push(next.first);
            }
        }
    }
    for (int i = 1; i < N; ++i)
    {
        if (cost[N][i])
            cout << i << " " << cost[N][i] << "\n";
    }
    return 0;
}