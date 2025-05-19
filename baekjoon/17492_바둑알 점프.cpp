#include <iostream>
#include <vector>

using namespace std;

int N;
int dy[] = {1, 1, 1, -1, -1, -1, 0, 0}, dx[] = {1, -1, 0, 1, -1, 0, 1, -1};

bool isWin(const vector<vector<int>> &map)
{
    int count = 0;

    for (const vector<int> &i : map)
    {
        for (const int &j : i)
        {
            count += j == 2;
        }
    }

    return count == 1;
}

bool isPossible(const vector<vector<int>> &map)
{
    auto isOut = [](int x)
    {
        return x < 0 || x >= N;
    };

    if (isWin(map))
    {
        return true;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (map[i][j] == 2)
            {
                for (int k = 0; k < 8; ++k)
                {
                    int ny = dy[k] + i;
                    int nx = dx[k] + j;

                    if (isOut(ny) || isOut(nx) || map[ny][nx] != 2)
                    {
                        continue;
                    }

                    int nny = dy[k] * 2 + i;
                    int nnx = dx[k] * 2 + j;

                    if (isOut(nny) || isOut(nnx) || map[nny][nnx] != 0)
                    {
                        continue;
                    }

                    auto nextMap = map;
                    nextMap[i][j] = 0;
                    nextMap[ny][nx] = 0;
                    nextMap[nny][nnx] = 2;

                    if (isPossible(nextMap))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    vector<vector<int>> map = vector<vector<int>>(N, vector<int>(N));

    for (vector<int> &i : map)
    {
        for (int &j : i)
        {
            cin >> j;
        }
    }

    cout << (isPossible(map) ? "Possible" : "Impossible");

    return 0;
}
