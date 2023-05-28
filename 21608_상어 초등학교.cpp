#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, sum = 0;
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N)), input(N * N + 1, vector<int>(4));
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}, score[] = {0, 1, 10, 100, 1000};
    for (int i = 0; i < N * N; ++i)
    {
        int cur;
        cin >> cur;
        for (int j = 0; j < 4; ++j)
            cin >> input[cur][j];
        int cnt = 0, empty = 0, curX = 21, curY = 21;
        for (int y = 0; y < N; ++y)
            for (int x = 0; x < N; ++x)
            {
                if (map[y][x])
                    continue;
                int tempC = 0, tempE = 0;
                for (int j = 0; j < 4; ++j)
                {
                    int ny = y + dy[j], nx = x + dx[j];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                        continue;
                    for (int k = 0; k < 4; ++k)
                        if (map[ny][nx] == input[cur][k])
                        {
                            ++tempC;
                            break;
                        }
                    if (!map[ny][nx])
                        ++tempE;
                }
                if (tempC > cnt)
                {
                    cnt = tempC;
                    empty = tempE;
                    curX = x;
                    curY = y;
                }
                else if (tempC == cnt && tempE > empty)
                {
                    empty = tempE;
                    curX = x;
                    curY = y;
                }
                else if (tempC == cnt && tempE == empty)
                {
                    if (curY > y)
                    {
                        curX = x;
                        curY = y;
                    }
                    else if (curY == y && curX > x)
                        curX = x;
                }
            }
        map[curY][curX] = cur;
    }
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < N; ++x)
        {
            int cur = map[y][x], cnt = 0;
            for (int i = 0; i < 4; ++i)
            {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                    continue;
                for (int j = 0; j < 4; ++j)
                    if (map[ny][nx] == input[cur][j])
                    {
                        ++cnt;
                        break;
                    }
            }
            sum += score[cnt];
        }
    cout << sum;
    return 0;
}