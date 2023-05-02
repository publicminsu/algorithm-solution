#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v, arr;
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
    for (int i = idx; i < N; ++i)
    {
        arr[depth] = v[i];
        dfs(i + 1, depth + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    v = vector<int>(N);
    arr = vector<int>(M);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    dfs(0, 0);
    return 0;
}