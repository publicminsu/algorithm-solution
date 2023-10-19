#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 101
using namespace std;

int map[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N, height;
void dfs(int y, int x)
{
    visit[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N)
            continue;
        if (!visit[nextY][nextX] && map[nextY][nextX] > height)
            dfs(nextY, nextX);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ret = 1, minH = 101, maxH = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            minH = min(minH, map[i][j]);
            maxH = max(maxH, map[i][j]);
        }
    }
    for (height = minH; height <= maxH; ++height)
    {
        int cnt = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (!visit[i][j] && map[i][j] > height)
                {
                    dfs(i, j);
                    ++cnt;
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret;
    return 0;
}