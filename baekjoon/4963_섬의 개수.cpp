#include <iostream>
#include <queue>
using namespace std;
struct pos
{
    int y, x;
    const pos operator+(const pos &other) const
    {
        return {this->y + other.y, this->x + other.x};
    }
};
bool map[50][50];
const pos d[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int w, h, cnt;
    queue<pos> q;

    while (true)
    {
        cin >> w >> h;

        if (w == 0)
        {
            break;
        }

        cnt = 0;

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (!map[i][j]) // 사용할 수 없는 땅인가?
                {
                    continue;
                }

                ++cnt;

                map[i][j] = false;
                q.push({i, j});

                while (!q.empty())
                {
                    pos cur = q.front();
                    q.pop();
                    for (int k = 0; k < 8; ++k)
                    {
                        pos next = cur + d[k];
                        if (next.y < 0 || next.x < 0 || next.y >= h || next.x >= w || !map[next.y][next.x]) // 범위를 벗어나는가?, 사용할 수 없는 땅인가?
                        {
                            continue;
                        }
                        map[next.y][next.x] = 0;
                        q.push(next);
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}