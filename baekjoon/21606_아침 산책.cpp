#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef unsigned long long ull;
int N;
ull ret = 0;
string A;
vector<vector<int>> graph;
vector<bool> visted;
ull bfs(int i)
{
    ull cnt = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur])
        {
            if (A[next - 1] == '0')
            {
                if (visted[next])
                    continue;
                visted[next] = true;
                q.push(next);
            }
            else
            {
                ++cnt;
            }
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> A;
    graph = vector<vector<int>>(N + 1, vector<int>());
    visted = vector<bool>(N + 1);
    for (int i = 1, u, v; i < N; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        if (A[u - 1] == '1' && A[v - 1] == '1')
            ret += 2;
    }
    for (int i = 1; i <= N; ++i)
    {
        if (visted[i] || A[i - 1] == '1')
            continue;
        visted[i] = true;
        ull cnt = bfs(i);
        ret += cnt * (cnt - 1);
    }
    cout << ret;
    return 0;
}