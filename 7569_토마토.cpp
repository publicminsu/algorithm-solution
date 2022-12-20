#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int map[101][101][101];
int dx[] = {-1, 1, 0, 0, 0, 0}, dy[] = {0, 0, -1, 1, 0, 0}, dz[] = {0, 0, 0, 0, -1, 1};
struct node
{
    int z, y, x, day;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<node> bfs;
    int M, N, H, count = 0, day = 1;
    cin >> M >> N >> H;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                int n;
                cin >> n;
                if (n == 1)
                    bfs.push({i, j, k, 1});
                else if (n == 0)
                    ++count;
                map[i][j][k] = n;
            }
        }
    }
    if (count == 0)
    {
        cout << '0';
        return 0;
    }
    while (!bfs.empty())
    {
        node n = bfs.front();
        bfs.pop();
        for (int i = 0; i < 6; ++i)
        {
            node next = {n.z + dz[i], n.y + dy[i], n.x + dx[i], n.day + 1};
            if (next.z >= 0 && next.z < H && next.y >= 0 && next.y < N && next.x >= 0 && next.x < M && !map[next.z][next.y][next.x])
            {
                map[next.z][next.y][next.x] = day;
                bfs.push(next);
                day = max(day, n.day);
                --count;
            }
        }
    }
    if (count > 0)
    {
        cout << "-1";
    }
    else
    {
        cout << day;
    }
    return 0;
}