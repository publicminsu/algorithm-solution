#include <iostream>
#include <vector>
using namespace std;

int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

int N, M;
vector<string> map;
vector<vector<bool>> isVisited;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    isVisited = vector<vector<bool>>(N, vector<bool>(M));
    map = vector<string>(N);

    for (string &str : map)
    {
        cin >> str;
    }
}

void dfs(int y, int x)
{
    if (isVisited[y][x])
    {
        return;
    }

    isVisited[y][x] = true;

    if (y == N - 1)
    {
        cout << "YES";
        exit(0);
    }

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == '1')
        {
            continue;
        }

        dfs(ny, nx);
    }
}

int main()
{
    input();

    for (int i = 0; i < M; ++i)
    {
        dfs(0, i);
    }

    cout << "NO";

    return 0;
}