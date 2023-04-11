#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dp, graph;
vector<int> popul;
vector<bool> visted;
int N, A, B;
void dfs(int cur)
{
    visted[cur] = true;
    dp[0][cur] = popul[cur];
    for (int next : graph[cur])
    {
        if (visted[next])
            continue;
        dfs(next);
        dp[1][cur] += max(dp[0][next], dp[1][next]);
        dp[0][cur] += dp[1][next];
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    dp = vector<vector<int>>(2, vector<int>(N + 1));
    graph = vector<vector<int>>(N + 1, vector<int>());
    popul = vector<int>(N + 1);
    visted = vector<bool>(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> popul[i];
    for (int i = 1; i < N; ++i)
    {
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    dfs(1);
    cout << max(dp[0][1], dp[1][1]);
    return 0;
}