#include <iostream>
#include <queue>
#include <vector>
#define LIMIT 987654321
using namespace std;
vector<vector<int>> graph, dp;
int N, full;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    full = (1 << N) - 1;
    dp = vector<vector<int>>(N, vector<int>(full + 1, -1));
    graph = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> graph[i][j];
        }
    }
}
int dfs(int cur, int mask)
{
    if (mask == full) // 다 방문했을 경우 돌아오는 비용
    {
        return graph[cur][0] ? graph[cur][0] : LIMIT;
    }

    if (dp[cur][mask] != -1) // 만약 이미 방문한 값이면
    {
        return dp[cur][mask];
    }
    dp[cur][mask] = LIMIT; // 방문하지 않은 값이면 높은 값으로 변경

    for (int next = 1; next < N; ++next)
    {
        int target = 1 << next;
        if ((mask & target) || !graph[cur][next]) // 이미 방문했거나 값이 없는 경우
        {
            continue;
        }
        dp[cur][mask] = min(dp[cur][mask], dfs(next, mask | target) + graph[cur][next]);
    }

    return dp[cur][mask];
}
int main()
{
    input();
    cout << dfs(0, 1);
    return 0;
}