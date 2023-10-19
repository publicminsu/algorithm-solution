#include <iostream>
#include <vector>
using namespace std;
vector<int> parent, depth;
vector<vector<int>> tree;
vector<bool> isVisited;
int N, M;
void dfs(int cur, int d)
{
    for (int next : tree[cur])
    {
        if (isVisited[next])
            continue;
        isVisited[next] = true;
        parent[next] = cur;
        depth[next] = d + 1;
        dfs(next, d + 1);
    }
}
void lca(int n1, int n2)
{
    while (depth[n1] < depth[n2])
        n2 = parent[n2];
    while (depth[n1] > depth[n2])
        n1 = parent[n1];
    while (n1 != n2)
    {
        n1 = parent[n1];
        n2 = parent[n2];
    }
    cout << n1 << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    isVisited = vector<bool>(N + 1);
    parent = depth = vector<int>(N + 1);
    tree = vector<vector<int>>(N + 1, vector<int>());
    int n1, n2;
    for (int i = 1; i < N; ++i)
    {
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    isVisited[1] = true;
    dfs(1, 0);
    cin >> M;
    while (M--)
    {
        cin >> n1 >> n2;
        lca(n1, n2);
    }
    return 0;
}