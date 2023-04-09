#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, R, Q, idx = 3;
vector<vector<int>> graph;
vector<int> dp;
vector<bool> visted;
void dfs(int cur)
{
    visted[cur] = true;
    for (int next : graph[cur])
    {
        if (visted[next])
            continue;
        dfs(next);
        dp[cur] += dp[next];
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> R >> Q;
    graph = vector<vector<int>>(N + 1, vector<int>());
    visted = vector<bool>(N + 1);
    dp = vector<int>(N + 1, 1);
    for (int i = 1, U, V; i < N; ++i)
    {
        cin >> U >> V;
        graph[U].push_back(V);
        graph[V].push_back(U);
    }
    dfs(R);
    while (Q--)
    {
        int U;
        cin >> U;
        cout << dp[U] << "\n";
    }
    return 0;
}