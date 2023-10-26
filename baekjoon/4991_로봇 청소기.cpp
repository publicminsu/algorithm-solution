#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int graph[10][10];
int graphNum[20][20];
char map[20][20];
int isVistied[20][20];
int w, h, graphSize, ret, full;
struct node
{
    int y, x;
    const node operator+(const node &other) const
    {
        return {y + other.y, x + other.x};
    }
    const bool isOut() const // 범위를 벗어났는가?
    {
        return y < 0 || x < 0 || y >= h || x >= w || isVistied[y][x] != -1 || map[y][x] == 'x';
    }
} dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(int y, int x)
{
    memset(isVistied, -1, sizeof(isVistied));
    queue<node> q;
    q.push({y, x});
    isVistied[y][x] = 0;
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        for (node d : dir)
        {
            node next = cur + d;
            if (next.isOut())
            {
                continue;
            }
            isVistied[next.y][next.x] = isVistied[cur.y][cur.x] + 1;
            if (map[next.y][next.x] == 'o' || map[next.y][next.x] == '*') // 목표 지점인가?
            {
                graph[graphNum[y][x]][graphNum[next.y][next.x]] = isVistied[next.y][next.x];
            }
            q.push(next);
        }
    }
}
void dfs(int cur, int mask, int sum)
{
    if (sum >= ret) // 이미 더 적은 값으로 도달했다면
    {
        return;
    }
    if (mask == full)
    {
        ret = min(ret, sum);
        return;
    }
    for (int i = 1; i < graphSize; ++i)
    {
        if (mask & (1 << i)) // 이미 탐색한 부분인가?
        {
            continue;
        }
        if (!graph[cur][i]) // 만약 도달할 수 없었다면
        {
            ret = -1;
            return;
        }
        dfs(i, (mask | (1 << i)), sum + graph[cur][i]);
    }
}
void solve()
{
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (map[i][j] == 'o' || map[i][j] == '*')
            {
                bfs(i, j);
            }
        }
    }
    ret = 401;
    full = (1 << graphSize) - 1;
    dfs(0, 1, 0);
    if (ret == -1)
    {
        cout << -1;
    }
    else
    {
        cout << ret;
    }
    cout << "\n";
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        cin >> w >> h;
        if (w == 0)
        {
            break;
        }
        graphSize = 1;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> map[i][j];
                if (map[i][j] == '*') // 더러운 칸
                {
                    graphNum[i][j] = graphSize++;
                }
                else if (map[i][j] == 'o') // 로봇 청소기
                {
                    graphNum[i][j] = 0;
                }
            }
        }
        solve();
    }
}
int main()
{
    input();
    return 0;
}