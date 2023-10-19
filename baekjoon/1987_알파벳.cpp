#include <iostream>
#include <vector>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, R, C, ret = 0;
bool isVisted[26];
vector<vector<char>> map;
void dfs(int y, int x, int cnt)
{
    if (cnt > ret)
        ret = cnt;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C || isVisted[map[ny][nx] - 'A'])
            continue;
        isVisted[map[ny][nx] - 'A'] = true;
        dfs(ny, nx, cnt + 1);
        isVisted[map[ny][nx] - 'A'] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    map = vector<vector<char>>(R, vector<char>(C));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            cin >> map[i][j];
        }
    isVisted[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << ret;
    return 0;
}