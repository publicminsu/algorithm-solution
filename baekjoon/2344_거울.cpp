#include <iostream>

using namespace std;

int N, M;
int map[1000][1000];

int dy[] = {0, -1};
int dx[] = {1, 0};

int answers[4001];

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
}

int dfs(int y, int x, int dir)
{
    if (y < 0 || x < 0 || y >= N || x >= M)
    {
        if (x >= M)
        {
            return N * 2 + M - y;
        }

        return N * 2 + M * 2 - x;
    }

    if (map[y][x])
    {
        dir = (dir + 1) % 2;
    }

    return dfs(y + dy[dir], x + dx[dir], dir);
}

void solve()
{
    for (int i = 0; i < N; ++i)
    {
        int answer = dfs(i, 0, 0);
        answers[answer] = i + 1;
        cout << answer << " ";
    }

    for (int i = 0; i < M; ++i)
    {
        int answer = dfs(N - 1, i, 1);
        answers[answer] = N + i + 1;
        cout << answer << " ";
    }

    for (int i = N - 1; i >= 0; --i)
    {
        const int &answer = answers[N * 2 + M - i];
        cout << answer << " ";
    }

    for (int i = M - 1; i >= 0; --i)
    {
        const int &answer = answers[N * 2 + M * 2 - i];
        cout << answer << " ";
    }
}

int main()
{
    input();
    solve();
    return 0;
}