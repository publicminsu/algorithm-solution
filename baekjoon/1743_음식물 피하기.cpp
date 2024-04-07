#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> map;
int N, M, K, r, c, answer;
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    map = vector<vector<bool>>(N, vector<bool>(M));
    while (K--)
    {
        cin >> r >> c;
        map[--r][--c] = true;
    }
}
int dfs(int y, int x)
{
    int sum = 0;
    map[y][x] = false;

    for (int i = 0; i < 4; ++i)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || nx < 0 || ny >= N || nx >= M || !map[ny][nx])
        {
            continue;
        }

        sum += dfs(ny, nx);
    }

    return sum + 1;
}
void solve()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j])
            {
                answer = max(dfs(i, j), answer);
            }
        }
    }
}
int main()
{
    input();
    solve();
    cout << answer;
    return 0;
}