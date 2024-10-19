#include <iostream>
using namespace std;
int N, M;
char map[50][50];

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

bool hasYGuard(int x)
{
    for (int i = 0; i < N; ++i)
    {
        if (map[i][x] == 'X')
        {
            return true;
        }
    }
    return false;
}

bool hasXGuard(int y)
{
    for (int j = 0; j < M; ++j)
    {
        if (map[y][j] == 'X')
        {
            return true;
        }
    }
    return false;
}

int solve()
{
    int answer = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (hasXGuard(i) || hasYGuard(j))
            {
                continue;
            }

            map[i][j] = 'X';
            ++answer;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (hasXGuard(i) && hasYGuard(j))
            {
                continue;
            }

            map[i][j] = 'X';
            ++answer;
        }
    }

    return answer;
}

int main()
{
    input();
    cout << solve();
    return 0;
}