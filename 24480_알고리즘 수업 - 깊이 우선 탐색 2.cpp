#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> graph;
vector<int> visted;
int cnt = 0;
void dfs(int cur)
{
    for (int i : graph[cur])
    {
        if (visted[i])
            continue;
        visted[i] = ++cnt;
        dfs(i);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, R, n1, n2;
    cin >> N >> M >> R;
    graph = vector<vector<int>>(N + 1, vector<int>());
    visted = vector<int>(N + 1);
    for (int i = 0; i < M; ++i)
    {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    for (int i = 1; i <= N; ++i)
    {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }
    visted[R] = ++cnt;
    dfs(R);
    for (int i = 1; i <= N; ++i)
        cout << visted[i] << "\n";
    return 0;
}