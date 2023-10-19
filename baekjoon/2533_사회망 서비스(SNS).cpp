#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<vector<int>> graph, dp;
vector<bool> visted;
void dfs(int cur)
{
    dp[0][cur] = 1;
    for (int next : graph[cur])
    {
        if (visted[next])
            continue;
        visted[next] = true;
        dfs(next);
        dp[0][cur] += min(dp[0][next], dp[1][next]);
        dp[1][cur] += dp[0][next];
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    graph = vector<vector<int>>(N + 1, vector<int>());
    dp = vector<vector<int>>(2, vector<int>(N + 1));
    visted = vector<bool>(N + 1);
    for (int i = 1, u, v; i < N; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    visted[1] = true;
    dfs(1);
    cout << min(dp[0][1], dp[1][1]);
    return 0;
}