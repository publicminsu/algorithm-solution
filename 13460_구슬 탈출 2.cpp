#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int y, x;
} red, blue;
vector<vector<char>> map;
int N, M, dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1}, ret = 11;
bool isBlueFall(node &nextBlue, int &i)
{
    while (map[nextBlue.y + dy[i]][nextBlue.x + dx[i]] != '#') // 벽에 도달하기 전까지 확인
    {
        nextBlue.y += dy[i];
        nextBlue.x += dx[i];

        if (map[nextBlue.y][nextBlue.x] == 'O') // 파랑이 빠지는지 확인
        {
            return true;
        }
    }
    return false;
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    map = vector<vector<char>>(N, vector<char>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];

            if (map[i][j] == 'B')
            {
                blue = {i, j};
                map[i][j] = '.';
            }
            else if (map[i][j] == 'R')
            {
                red = {i, j};
                map[i][j] = '.';
            }
        }
    }
}
void dfs(node r, node b, int cnt)
{
    if (ret <= cnt) // 이미 더 낮은 값으로 도착했다면 반환
    {
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        node nextBlue = b;
        if (isBlueFall(nextBlue, i))
        {
            continue;
        }

        node nextRed = r;
        while (map[nextRed.y + dy[i]][nextRed.x + dx[i]] != '#')
        {
            nextRed.y += dy[i];
            nextRed.x += dx[i];

            if (map[nextRed.y][nextRed.x] == 'O') // 빨강이 빠지는지 확인
            {
                ret = min(ret, cnt);
                return;
            }
        }
        if (nextRed.y == nextBlue.y && nextRed.x == nextBlue.x)
        {
            int redLen = abs(nextRed.y - r.y) + abs(nextRed.x - r.x);
            int blueLen = abs(nextBlue.y - b.y) + abs(nextBlue.x - b.x);

            if (redLen > blueLen) // 더 낮은 거리가 더 빨리 도착한 구슬
            {
                nextRed.y -= dy[i];
                nextRed.x -= dx[i];
            }
            else
            {
                nextBlue.y -= dy[i];
                nextBlue.x -= dx[i];
            }
        }
        dfs(nextRed, nextBlue, cnt + 1);
    }
}
int main()
{
    input();
    dfs(red, blue, 1);
    cout << (ret == 11 ? -1 : ret);
    return 0;
}