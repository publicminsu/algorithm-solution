#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[] = {1, -1, 0, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1};
struct node
{
    int z, y, x, time;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char map[31][31][31];
    int L, R, C;
    queue<node> bfs;
    while (true)
    {
        int time = -1;
        bfs = queue<node>();
        cin >> L >> R >> C;
        if (!L && !R && !C)
            break;
        for (int i = 0; i < L; ++i)
            for (int j = 0; j < R; ++j)
                for (int k = 0; k < C; ++k)
                {
                    char c;
                    cin >> c;
                    map[i][j][k] = c;
                    if (c == 'S')
                    {
                        map[i][j][k] = '#';
                        bfs.push({i, j, k, 0});
                    }
                }
        while (!bfs.empty())
        {
            node cur = bfs.front();
            bfs.pop();
            for (int i = 0; i < 6; ++i)
            {
                node next = {cur.z + dz[i], cur.y + dy[i], cur.x + dx[i], cur.time + 1};
                if (next.x < 0 || next.y < 0 || next.z < 0 || next.x >= C || next.y >= R || next.z >= L || map[next.z][next.y][next.x] == '#')
                    continue;
                if (map[next.z][next.y][next.x] == 'E')
                {
                    time = next.time;
                    break;
                }
                else
                {
                    map[next.z][next.y][next.x] = '#';
                    bfs.push(next);
                }
            }
        }
        if (time == -1)
        {
            cout << "Trapped!";
        }
        else
        {
            cout << "Escaped in " << time << " minute(s).";
        }
        cout << "\n";
    }
}