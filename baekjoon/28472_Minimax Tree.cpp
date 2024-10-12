#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
vector<int> values;
int N, R, u, v, L, k, t, Q, q;

int dfs(int depth, int cur)
{
    if (values[cur] != -1)
    {
        return values[cur];
    }

    values[cur] = 0;

    bool isMin = depth % 2;

    int value = isMin ? 1000000001 : -1;

    for (int next : graph[cur])
    {
        if (!values[next])
        {
            continue;
        }

        int nextValue = dfs(depth + 1, next);

        value = isMin ? min(value, nextValue) : max(value, nextValue);
    }

    return values[cur] = value;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> R;
    values = vector<int>(N + 1, -1);
    graph = vector<vector<int>>(N + 1, vector<int>());

    for (int i = 1; i < N; ++i)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cin >> L;

    for (int i = 0; i < L; ++i)
    {
        cin >> k >> t;
        values[k] = t;
    }

    dfs(0, R);

    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        cin >> q;

        cout << values[q] << "\n";
    }

    return 0;
}