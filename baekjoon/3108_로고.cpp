#include <iostream>
#include <queue>
using namespace std;
#define MAX 2001
bool map[MAX][MAX], isVisited[MAX][MAX];
struct pos
{
    int y, x;
    const pos operator+(const pos &other) const
    {
        return {other.y + y, other.x + x};
    }
    bool isOut() // 가능한 범위를 벗어났는가?
    {
        return x < 0 || y < 0 || x >= MAX || y >= MAX || !map[y][x] || isVisited[y][x];
    }
} dir[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct rect
{
    pos p1, p2;
} rects[MAX];
int N;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> rects[i].p1.x >> rects[i].p1.y >> rects[i].p2.x >> rects[i].p2.y;

        // 음수를 제거하고 간격을 벌려준다.
        rects[i].p1.x = (rects[i].p1.x + 500) << 1;
        rects[i].p1.y = (rects[i].p1.y + 500) << 1;
        rects[i].p2.x = (rects[i].p2.x + 500) << 1;
        rects[i].p2.y = (rects[i].p2.y + 500) << 1;

        for (int j = rects[i].p1.y; j <= rects[i].p2.y; ++j) // 세로선을 그어준다.
        {
            map[j][rects[i].p1.x] = true;
            map[j][rects[i].p2.x] = true;
        }

        for (int j = rects[i].p1.x; j <= rects[i].p2.x; ++j) // 가로선을 그어준다.
        {
            map[rects[i].p1.y][j] = true;
            map[rects[i].p2.y][j] = true;
        }
    }
}
void bfs(const pos &p)
{
    queue<pos> q;
    q.push(p);

    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();

        for (pos d : dir)
        {
            pos next = cur + d;

            if (next.isOut())
            {
                continue;
            }

            isVisited[next.y][next.x] = true;
            q.push(next);
        }
    }
}
void solve()
{
    int cnt = 0;

    if (map[1000][1000]) // 0, 0지점
    {
        bfs({1000, 1000});
    }

    for (int i = 0; i < N; ++i) // 이전 탐색으로 방문하지 않은 부분을 탐색한다.
    {
        if (isVisited[rects[i].p1.y][rects[i].p1.x])
        {
            continue;
        }

        ++cnt;
        bfs(rects[i].p1);
    }

    cout << cnt;
}
int main()
{
    input();
    solve();
    return 0;
}