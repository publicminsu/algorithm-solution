#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v, arr;
vector<bool> visted;
int N, M;
void dfs(int idx, int depth)
{
    if (depth == M)
    {
        for (int i : arr)
            cout << i << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; ++i)
    {
        if (visted[i])
            continue;
        arr[depth] = v[i];
        visted[i] = true;
        dfs(i + 1, depth + 1);
        visted[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    arr = vector<int>(M);
    visted = vector<bool>(M);
    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    dfs(0, 0);
    return 0;
}