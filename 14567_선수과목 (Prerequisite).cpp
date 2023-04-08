#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, A, B;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> indegree(N + 1);
    vector<int> cost(N + 1, 0);
    queue<int> q;

    while (M--)
    {
        cin >> A >> B;
        ++indegree[B];
        graph[A].push_back(B);
    }
    for (int i = 1; i <= N; ++i)
        if (!indegree[i]) // 0인 값부터 학기를 초기화하며 큐에 넣는다.
        {
            q.push(i);
            cost[i] = 1;
        }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur])
            if (!(--indegree[next])) // 진입차수를 줄여가고 0되면 학기를 갱신하고 큐에 넣는다.
            {
                cost[next] = cost[cur] + 1;
                q.push(next);
            }
    }
    for (int i = 1; i <= N; ++i)
        cout << cost[i] << " ";
    return 0;
}