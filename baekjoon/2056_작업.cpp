#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> cost, indegree, dp;
vector<vector<int>> graph;
int N;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    cost = indegree = dp = vector<int>(N + 1);
    graph = vector<vector<int>>(N + 1, vector<int>());

    for (int i = 1, j, c, amount; i <= N; ++i)
    {
        cin >> c >> amount;
        cost[i] = c;
        indegree[i] = amount;
        while (amount--)
        {
            cin >> j;
            graph[j].push_back(i);
        }
    }
}
int solve()
{
    queue<int> q;

    for (int i = 1; i <= N; ++i)
    {
        if (indegree[i] == 0) // 진입 차수가 0인 경우
        {
            q.push(i);
            dp[i] = cost[i];
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            dp[next] = max(dp[next], dp[cur] + cost[next]); // 지금 작업이 끝나야 다음 작업이 완료됨

            if (--indegree[next] == 0) // 진입 차수가 0인 경우
            {
                q.push(next);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        answer = max(answer, dp[i]);
    }
    return answer;
}
int main()
{
    input();
    cout << solve();
    return 0;
}