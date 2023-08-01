#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> kevin;
vector<vector<int>> graph;
int N, M, ret, minKevin = 101;
int bfs(int start)
{
    int ret = 0;
    fill(kevin.begin(), kevin.end(), -1);
    kevin[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur])
        {
            if (kevin[next] != -1)
                continue;
            kevin[next] = kevin[cur] + 1;
            ret += kevin[next];
            q.push(next);
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    graph = vector<vector<int>>(N + 1, vector<int>());
    kevin = vector<int>(N + 1);
    while (M--)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    for (int i = 1; i <= N; ++i)
    {
        int k = bfs(i);
        if (minKevin > k)
        {
            ret = i;
            minKevin = k;
        }
    }
    cout << ret;
    return 0;
}