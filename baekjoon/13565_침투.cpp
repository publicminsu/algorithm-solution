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

bool dfs(int y, int x)
{
    if (isVisited[y][x])
    {
        return false;
    }

    isVisited[y][x] = true;

    if (y == N - 1)
    {
        return true;
    }

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] == '1')
        {
            continue;
        }

        bool value = dfs(ny, nx);

        if (value)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    input();

    for (int i = 0; i < M; ++i)
    {
        if (dfs(0, i))
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}