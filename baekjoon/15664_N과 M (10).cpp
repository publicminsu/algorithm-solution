#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr, ret;
int N, M;
void dfs(int idx, int depth)
{
    if (depth == M)
    {
        for (int i : ret)
            cout << i << " ";
        cout << "\n";
        return;
    }
    for (int i = idx, prev = 0; i < N; ++i)
    {
        if (prev == arr[i])
            continue;
        prev = arr[i];
        ret[depth] = arr[i];
        dfs(i + 1, depth + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    arr = vector<int>(N);
    ret = vector<int>(M);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    dfs(0, 0);
    return 0;
}