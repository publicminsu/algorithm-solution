#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> arr, ret;
void dfs(int depth)
{
    if (depth == M)
    {
        for (int i : ret)
            cout << i << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; ++i)
    {
        if (ret[depth] == arr[i])
            continue;
        ret[depth] = arr[i];
        dfs(depth + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    ret = vector<int>(M);
    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        arr.push_back(j);
    }
    sort(arr.begin(), arr.end());
    dfs(0);
    return 0;
}