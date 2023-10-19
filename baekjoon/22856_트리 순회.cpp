#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int N;
vector<pii> tree;
int dfs(int cur, int depth)
{
    int lastDepth;
    if (tree[cur].first != -1)
        lastDepth = dfs(tree[cur].first, depth + 1);
    lastDepth = depth;
    if (tree[cur].second != -1)
        lastDepth = dfs(tree[cur].second, depth + 1);
    return lastDepth;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    tree = vector<pii>(N + 1);
    for (int i = 0, a, b, c; i < N; ++i)
    {
        cin >> a >> b >> c;
        tree[a].first = b;
        tree[a].second = c;
    }
    int lastDepth = dfs(1, 0);
    cout << (N - 1) * 2 - lastDepth;
    return 0;
}