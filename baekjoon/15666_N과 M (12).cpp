#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr, A;
int N, M;
void dfs(int idx, int depth)
{
    if (depth == M)
    {
        for (int i : A)
            cout << i << " ";
        cout << "\n";
        return;
    }
    for (int i = idx; i < arr.size(); ++i)
    {
        A[depth] = arr[i];
        dfs(i, depth + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    A = vector<int>(M);
    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        arr.push_back(j);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    dfs(0, 0);
}