#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
vector<vector<int>> graph;
vector<ll> islands;
vector<int> indegree;
int N, a, p;
char t;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    indegree = vector<int>(N + 1);
    islands = vector<ll>(N + 1);
    graph = vector<vector<int>>(N + 1, vector<int>());

    for (int i = 2; i <= N; ++i)
    {
        cin >> t >> a >> p;
        if (t == 'S') // 양
        {
            islands[i] = a;
        }
        else // 늑대
        {
            islands[i] = -a;
        }
        graph[i].push_back(p);
        ++indegree[p];
    }
}
void solve()
{
    queue<int> q;
    for (int i = 2; i <= N; ++i)
    {
        if (indegree[i] == 0) // 진입차수가 없다면
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            if (islands[cur] > 0) // 양일 경우
            {
                islands[next] += islands[cur];
            }
            if (--indegree[next] == 0) // 진입차수가 없다면
            {
                q.push(next);
            }
        }
    }
}
int main()
{
    input();
    solve();
    cout << islands[1];
    return 0;
}