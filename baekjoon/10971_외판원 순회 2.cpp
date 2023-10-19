#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
vector<bool> visted;
int N, ret = 11000001;
void dfs(int cur, int cnt, int sum, int parent)
{
    if (sum >= ret)
        return;
    if (cnt == N) // 모두 방문했다면
    {
        int last = graph[cur][parent];
        if (!last) // 돌아갈 수 없다면 반환
            return;
        sum += last;
        ret = sum < ret ? sum : ret;
    }
    for (int i = 0; i < N; ++i)
    {
        if (visted[i] || !graph[cur][i]) // 방문했거나 방문할 수 없다면
            continue;
        visted[i] = true;
        dfs(i, cnt + 1, sum + graph[cur][i], parent);
        visted[i] = false;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    graph = vector<vector<int>>(N, vector<int>(N));
    visted = vector<bool>(N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> graph[i][j];
        }
    for (int i = 0; i < N; ++i)
    {
        visted[i] = true;
        dfs(i, 1, 0, i);
    }
    cout << ret;
    return 0;
}