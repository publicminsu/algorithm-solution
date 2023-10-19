#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<vector<int>> dp;
int farm(int l, int r, int depth)
{
    if (l > r)
        return 0;
    if (dp[l][r])
        return dp[l][r];
    return dp[l][r] = max(v[l] * depth + farm(l + 1, r, depth + 1), v[r] * depth + farm(l, r - 1, depth + 1));
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    v = vector<int>(N);
    dp = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }
    cout << farm(0, N - 1, 1);
    return 0;
}