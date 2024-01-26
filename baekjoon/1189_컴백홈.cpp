#include <iostream>
#include <vector>
using namespace std;
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
int R, C, K, answer;
vector<string> map;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> R >> C >> K;
    map = vector<string>(R);

    for (int i = 0; i < R; ++i)
    {
        cin >> map[i];
    }
}
void dfs(int y, int x, int cnt)
{
    if (cnt == K) // 길이가 K일 때
    {
        if (y == 0 && x == C - 1) // 집에 도착했는지 확인
        {
            ++answer;
        }
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C || map[ny][nx] == 'T') // 범위를 벗어났는지, 가지 못하는 부분인지 확인
        {
            continue;
        }
        map[ny][nx] = 'T';
        dfs(ny, nx, cnt + 1);
        map[ny][nx] = '.';
    }
}
int main()
{
    input();
    map[R - 1][0] = 'T';
    dfs(R - 1, 0, 1);
    cout << answer;
    return 0;
}