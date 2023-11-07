#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, r1, c1, r2, c2;
vector<vector<int>> map;
struct node
{
    int r, c;
    const node operator+(node &other) const
    {
        return {r + other.r, c + other.c};
    }
    bool isOut()
    {
        return r < 0 || c < 0 || r >= N || c >= N || map[r][c] != -1;
    }
} dir[] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};
void input()
{
    scanf("%d%d%d%d%d", &N, &r1, &c1, &r2, &c2);
    map = vector<vector<int>>(N, vector<int>(N, -1)); //-1로 초기화
}
void bfs()
{
    queue<node> q;
    q.push({r1, c1});
    map[r1][c1] = 0;

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

            map[next.r][next.c] = map[cur.r][cur.c] + 1;
            if (next.r == r2 && next.c == c2) // 도착했는가?
            {
                return;
            }
            q.push(next);
        }
    }
}
int main()
{
    input();
    bfs();
    printf("%d", map[r2][c2]);
    return 0;
}