#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int map[101][101];
bool isVisited[101][101][4];
int N, M;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
vector<int> answer;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
        }
    }

    answer.reserve(N);
}

bool dfs(int y, int x, int dir)
{
    int dist = map[y][x];
    int ny = dy[dir] * dist + y;
    int nx = dx[dir] * dist + x;

    if (ny < 0 || nx < 0 || ny >= N || nx >= M)
    {
        return false;
    }

    if (isVisited[ny][nx][dir])
    {
        return true;
    }

    isVisited[ny][nx][dir] = true;

    dir = (dir + 1) % 4;

    return dfs(ny, nx, dir);
}

void solve()
{
    for (int i = 0; i < N; ++i)
    {
        memset(isVisited, false, sizeof(isVisited));

        if (dfs(i, 0, 0))
        {
            answer.push_back(i + 1);
        }
    }

    cout << answer.size() << "\n";

    for (const int &i : answer)
    {
        cout << i << " ";
    }
}

int main()
{
    input();
    solve();
    return 0;
}