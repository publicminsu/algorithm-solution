#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

using pii = pair<int, int>;

int N;
bool map[11][11];
bool isVisited[11][11];
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
queue<pii> q;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            char c;
            cin >> c;
            map[i][j] = c != '.';
        }
    }
}

int countArea()
{
    memset(isVisited, false, sizeof(isVisited));

    int areaCount = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (map[i][j] || isVisited[i][j])
            {
                continue;
            }

            ++areaCount;

            q.push({i, j});
            isVisited[i][j] = true;

            while (!q.empty())
            {
                pii curNode = q.front();
                q.pop();

                for (int k = 0; k < 4; ++k)
                {
                    int ny = curNode.first + dy[k];
                    int nx = curNode.second + dx[k];

                    if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                    {
                        continue;
                    }

                    if (map[ny][nx] || isVisited[ny][nx])
                    {
                        continue;
                    }

                    isVisited[ny][nx] = true;

                    q.push({ny, nx});
                }
            }
        }
    }

    return areaCount;
}

int countAmbushPoints()
{
    int value = 0;
    int areaCount = countArea();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (map[i][j])
            {
                continue;
            }

            map[i][j] = true;
            value += areaCount < countArea();
            map[i][j] = false;
        }
    }

    return value;
}

int main()
{
    input();
    cout << countAmbushPoints();
    return 0;
}