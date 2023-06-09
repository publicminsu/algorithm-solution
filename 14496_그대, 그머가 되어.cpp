#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    queue<int> q;
    int a, b, N, M, x, y;
    cin >> a >> b >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> cnt(N + 1, -1);
    while (M--)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cnt[a] = 0;
    q.push(a);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur])
        {
            if (cnt[next] != -1)
                continue;
            cnt[next] = cnt[cur] + 1;
            if (next == b)
                break;
            q.push(next);
        }
    }
    cout << cnt[b];
    return 0;
}