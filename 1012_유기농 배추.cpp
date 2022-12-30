#include <iostream>
#include <cstring>
using namespace std;
bool map[51][51];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, M, N;
void dfs(int y, int x)
{
    map[y][x] = false;
    for (int i = 0; i < 4; ++i)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M)
            continue;
        if (map[nextY][nextX])
        {
            dfs(nextY, nextX);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int K, cnt = 0;
        cin >> M >> N >> K;
        memset(map, false, sizeof(map));
        for (int i = 0; i < K; ++i)
        {
            int X, Y;
            cin >> X >> Y;
            map[Y][X] = true;
        }
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (map[i][j])
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}