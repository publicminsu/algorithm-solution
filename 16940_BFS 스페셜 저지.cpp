#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> graph(N + 1);
    vector<int> isVisted(N + 1), parent(N + 1), order(N + 1);
    for (int i = 1, j, k; i < N; ++i)
    {
        cin >> j >> k;
        graph[j].push_back(k);
        graph[k].push_back(j);
    }

    queue<int> q;
    q.push(1);
    isVisted[1] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur])
        {
            if (isVisted[next])
                continue;
            parent[next] = cur;
            isVisted[next] = isVisted[cur] + 1;
            q.push(next);
        }
    }
    int i;
    cin >> i;
    if (i != 1)
    {
        cout << 0;
        return 0;
    }
    for (int prevLevel = 1, next, prev = 1; i < N; ++i)
    {
        cin >> next;
        if (prevLevel > isVisted[next] || order[parent[prev]] > order[parent[next]])
        {
            cout << 0;
            return 0;
        }
        order[next] = i;
        prev = next;
        prevLevel = isVisted[next];
    }
    cout << 1;
    return 0;
}