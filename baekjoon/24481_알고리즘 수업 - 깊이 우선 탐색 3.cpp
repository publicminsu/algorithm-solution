#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, R;
vector<vector<int>> map;
vector<int> depths;

void dfs(int depth, int cur)
{
    if (depths[cur] != -1)
    {
        return;
    }

    depths[cur] = depth;

    sort(map[cur].begin(), map[cur].end());

    for (int index = 0; index < map[cur].size(); ++index)
    {
        dfs(depth + 1, map[cur][index]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> R;

    depths = vector<int>(N + 1, -1);
    map = vector<vector<int>>(N + 1, vector<int>());

    for (int index = 0, u, v; index < M; ++index)
    {
        cin >> u >> v;

        map[u].push_back(v);
        map[v].push_back(u);
    }

    dfs(0, R);

    for (int index = 1; index <= N; ++index)
    {
        cout << depths[index] << "\n";
    }
    return 0;
}