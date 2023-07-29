#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
int n;
vector<vector<int>> map, dp;
int dfs(int y, int x)
{
    if (dp[y][x])
        return dp[y][x];
    int ret = 0;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || map[y][x] >= map[ny][nx])
            continue;
        ret = max(dfs(ny, nx), ret);
    }
    return dp[y][x] = ret + 1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int ret = 0;
    cin >> n;
    map = dp = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> map[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (dp[i][j])
                continue;
            ret = max(ret, dfs(i, j));
        }
    cout << ret;
    return 0;
}