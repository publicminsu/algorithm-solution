#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, time, end;
    cin >> N;
    vector<int> inDegree(N + 1), timeV(N + 1), ret(N + 1);
    vector<vector<int>> graph(N + 1, vector<int>());
    queue<int> q;
    for (int i = 1; i <= N; ++i)
    {
        cin >> time;
        timeV[i] = time;
        ret[i] = time;
        while (true)
        {
            cin >> end;
            if (end == -1)
                break;
            ++inDegree[i];
            graph[end].push_back(i);
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (!inDegree[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur])
        {
            ret[next] = max(ret[next], ret[cur] + timeV[next]);
            if (!(--inDegree[next]))
            {
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= N; ++i)
        cout << ret[i] << "\n";
    return 0;
}