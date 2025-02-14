#include <iostream>
using namespace std;

int N, M, blackValue, whiteValue;
char map[100][100];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int GetCount(int y, int x, char BW)
{
    int count = 0;

    map[y][x] = '.';

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= M || nx >= N)
        {
            continue;
        }

        if (map[ny][nx] == BW)
        {
            count += GetCount(ny, nx, BW);
        }
    }

    return count + 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            char BW = map[i][j];

            if (BW == 'W' || BW == 'B')
            {
                int count = GetCount(i, j, BW);

                switch (BW)
                {
                case 'W':
                    whiteValue += count * count;
                    break;
                case 'B':
                    blackValue += count * count;
                    break;
                }
            }
        }
    }

    cout << whiteValue << " " << blackValue;
    return 0;
}