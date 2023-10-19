#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int N;
vector<pii> tree;
void dfs(int cur, ull K)
{
    if (tree[cur].first != -1 && tree[cur].second != -1)
    {
        if (K % 2)
            dfs(tree[cur].first, (K >> 1) + 1);
        else
            dfs(tree[cur].second, K >> 1);
    }
    else if (tree[cur].first != -1)
        dfs(tree[cur].first, K);
    else if (tree[cur].second != -1)
        dfs(tree[cur].second, K);
    else
        cout << cur;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    tree = vector<pii>(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> tree[i].first >> tree[i].second;
    ull K;
    cin >> K;
    dfs(1, K);
    return 0;
}