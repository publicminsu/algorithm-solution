#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, h, w, K;
vector<vector<int>> map;
struct pos
{
    int y, x;
    const pos operator+(const pos &other) const
    {
        return {y + other.y, x + other.x};
    }
    const bool isOut()
    {
        return y < 0 || x < 0 || y >= N || x >= M;
    }
} dir[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void flush(int y, int x) // 하수구 물 내리기
{
    queue<pos> q;
    q.push({y, x});
    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();
        if (!map[cur.y][cur.x])
        {
            continue;
        }
        for (pos d : dir)
        {
            pos next = cur + d;
            if (next.isOut())
            {
                continue;
            }
            if (map[cur.y][cur.x] <= map[next.y][next.x]) // 낮거나 같은 칸
            {
                q.push(next);
            }
        }
        map[cur.y][cur.x] = 0;
    }
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> h >> w;
    map = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
        }
    }
    cin >> K;
    while (K--)
    {
        int r, c;
        cin >> r >> c;
        if (map[r - 1][c - 1])
        {
            flush(r - 1, c - 1);
        }
    }
}
bool isEmpty(int y, int x) // 신발이 들어갈 수 있는가?
{
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (map[i + y][j + x])
            {
                return false;
            }
        }
    }
    return true;
}
int count()
{
    int cnt = 0;
    for (int i = 0; i < N - h + 1; ++i)
    {
        for (int j = 0; j < M - w + 1; ++j)
        {
            if (isEmpty(i, j))
            {
                ++cnt;
            }
        }
    }
    return cnt;
}
int main()
{
    input();
    cout << count();
    return 0;
}