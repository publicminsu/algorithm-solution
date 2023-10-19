#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[8], ret[8], cnt[10001];
void dfs(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; ++i)
            cout << ret[i] << " ";
        cout << "\n";
        return;
    }
    int prev = 0;
    for (int i = 0; i < N; ++i)
    {
        if (prev != arr[i] && cnt[arr[i]])
        {
            --cnt[arr[i]];
            prev = ret[depth] = arr[i];
            dfs(depth + 1);
            ++cnt[arr[i]];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        ++cnt[arr[i]];
    }
    sort(arr, arr + N);
    dfs(0);
}