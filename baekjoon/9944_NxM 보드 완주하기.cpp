#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, M, ret, dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1}, cnt;
bool map[30][30];
int getLen(int y, int x, int dir)
{
    for (int i = 1; i <= 30; ++i)
    {
        int ny = y + dy[dir] * i, nx = x + dx[dir] * i;
        if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx])
        {
            return i; // 1이면 사실상 바로 앞에서 막힌 것
        }
    }
}

void build(int y, int x, int dir, int len, bool isBuild)
{
    for (int i = 1; i < len; ++i) // 막히기 직전까지 칠해준다
    {
        int ny = y + dy[dir] * i, nx = x + dx[dir] * i;
        map[ny][nx] = isBuild;
    }
}
void dfs(int y, int x, int depth)
{
    if (depth >= ret) // 이전 기록보다 더 많이 확인할 필요는 없다.
        return;
    for (int i = 0; i < 4; ++i)
    {
        int len = getLen(y, x, i);
        if (len == 1)
            continue;
        build(y, x, i, len, true);
        int ny = y + dy[i] * (len - 1), nx = x + dx[i] * (len - 1);
        cnt += len - 1;
        dfs(ny, nx, depth + 1);
        cnt -= len - 1;
        build(y, x, i, len, false);
    }
    if (cnt == N * M) // 모든 방을 탐색 완료
    {
        ret = depth < ret ? depth : ret;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    char k;
    int tc = 0;
    while (true)
    {
        cin >> N >> M;
        if (cin.eof())
            break;
        cnt = 1; // 시작 지점
        ret = 1000001;
        memset(map, false, sizeof(map));

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                cin >> k;
                if (k == '*')
                {
                    ++cnt;
                    map[i][j] = true;
                }
            }

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                if (map[i][j])
                    continue;
                map[i][j] = true;
                dfs(i, j, 0);
                map[i][j] = false;
            }

        if (ret == 1000001)
            ret = -1;
        cout << "Case " << ++tc << ":"
             << " " << ret << "\n";
    }
    return 0;
}