#include <iostream>
#include <vector>
using namespace std;
int M, N, dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
vector<vector<int>> dp, map;
int dfs(int y, int x)
{
    if (dp[y][x] != -1)
        return dp[y][x];
    int ret = 0;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < M && nx < N && ny >= 0 && nx >= 0 && map[y][x] > map[ny][nx])
            ret += dfs(ny, nx);
    }
    return dp[y][x] = ret;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> M >> N;
    map = dp = vector<vector<int>>(M, vector<int>(N, -1));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];
    dp[M - 1][N - 1] = 1;
    dfs(0, 0);
    cout << dp[0][0];
    return 0;
}