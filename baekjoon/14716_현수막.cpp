#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> banner;
int M, N;
struct pos
{
    int y, x;
    const pos operator+(const pos &other) const
    {
        return {y + other.y, x + other.x};
    }
    const bool isOut() const
    {
        return y < 0 || x < 0 || y >= M || x >= N || banner[y][x] == 0;
    }
} dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> M >> N;
    banner = vector<vector<int>>(M, vector<int>(N));
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> banner[i][j];
        }
    }
}
int solve()
{
    int ret = 0;
    queue<pos> q;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (banner[i][j] == 0) // 글자가 없거나 이미 사용한 부분인 경우
            {
                continue;
            }
            ++ret;            // 처음 해당 글자에 도달하였으니 글자의 개수를 올려준다.
            banner[i][j] = 0; // 글자를 없앤다.

            q.push({i, j});
            while (!q.empty())
            {
                pos cur = q.front();
                q.pop();
                for (pos d : dir)
                {
                    pos next = cur + d;
                    if (next.isOut()) // 범위를 벗어났는가?
                    {
                        continue;
                    }

                    banner[next.y][next.x] = 0; // 글자를 없앤다.
                    q.push(next);
                }
            }
        }
    }

    return ret;
}
int main()
{
    input();
    cout << solve();
    return 0;
}