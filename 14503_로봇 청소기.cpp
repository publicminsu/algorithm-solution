#include <iostream>
#include <vector>
using namespace std;
int N, M, cnt = 0;
vector<vector<int>> map;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
bool isDirty(int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (!map[ny][nx])
            return true;
    }
    return false;
}
void dfs(int y, int x, int dir)
{
    if (!map[y][x]) // 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
    {
        map[y][x] = 2;
        ++cnt;
    }
    if (isDirty(y, x)) // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
    {
        while (true)
        {
            dir = (dir + 3) % 4; // 반시계 방향으로 회전한다.
            int ny = y + dy[dir], nx = x + dx[dir];
            if (!map[ny][nx]) // 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
            {
                dfs(ny, nx, dir);
                break;
            }
        }
    }
    else // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
    {
        int backDir = (dir + 2) % 4;
        int ny = y + dy[backDir], nx = x + dx[backDir];
        if (map[ny][nx] != 1) // 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
        {
            dfs(ny, nx, dir);
        }
        // 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    map = vector<vector<int>>(N, vector<int>(M));
    int y, x, dir;
    cin >> y >> x >> dir;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
        }
    dfs(y, x, dir);
    cout << cnt;
    return 0;
}