#include <iostream>
using namespace std;
int map[19][19], dy[] = {-1, 0, 1, 1}, dx[] = {1, 1, 1, 0};
bool isWin(int y, int x, int dir)
{
    for (int i = 1; i < 5; ++i)
    {
        int ny = y + dy[dir] * i;
        int nx = x + dx[dir] * i;
        if (ny >= 19 || nx >= 19 || ny < 0)
            return false;
        if (map[ny][nx] != map[y][x])
            return false;
    }
    int ny = y + dy[dir] * 5;
    int nx = x + dx[dir] * 5;
    if (ny >= 0 && ny < 19 && nx < 19 && map[ny][nx] == map[y][x])
        return false;
    ny = y + dy[dir] * -1;
    nx = x + dx[dir] * -1;
    if (ny >= 0 && ny < 19 && nx < 19 && map[ny][nx] == map[y][x])
        return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0; i < 19; ++i)
        for (int j = 0; j < 19; ++j)
            cin >> map[i][j];
    for (int i = 0; i < 19; ++i)
        for (int j = 0; j < 19; ++j)
            if (map[i][j])
                for (int k = 0; k < 4; ++k)
                    if (isWin(i, j, k))
                    {
                        cout << map[i][j] << "\n"
                             << i + 1 << " " << j + 1;
                        return 0;
                    }
    cout << 0;
    return 0;
}