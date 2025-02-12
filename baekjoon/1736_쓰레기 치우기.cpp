#include <iostream>
using namespace std;
int N, M, answer, trash;
int map[100][100];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int &k = map[i][j];
            cin >> k;
            trash += k;
        }
    }
}

void useRobot(int y, int x)
{
    for (int i = y; i < N; ++i)
    {
        for (int j = x; j < M; ++j)
        {
            int &value = map[i][j];

            if (value)
            {
                value = 0;
                --trash;
                useRobot(i, j);
                return;
            }
        }
    }
}

void solve()
{
    while (trash)
    {
        useRobot(0, 0);
        ++answer;
    }

    cout << answer;
}

int main()
{
    input();
    solve();
    return 0;
}