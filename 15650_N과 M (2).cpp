#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int N, M;
void dfs(int idx, int depth)
{
    if (depth == M)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = idx; i <= N; ++i)
    {
        v[depth] = i;
        dfs(i + 1, depth + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    v = vector<int>(M);
    dfs(1, 0);
    return 0;
}