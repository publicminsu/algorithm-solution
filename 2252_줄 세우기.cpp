#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, a, b;
    cin >> N >> M;
    queue<int> q;
    vector<int> inDegree(N + 1);
    vector<vector<int>> graph(N + 1, vector<int>());
    while (M--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        ++inDegree[b];
    }
    for (int i = 1; i <= N; ++i)
        if (!inDegree[i])
            q.push(i);
    while (!q.empty())
    {
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for (int next : graph[cur])
        {
            if (--inDegree[next] == 0)
                q.push(next);
        }
    }
}