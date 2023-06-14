#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppp; // 거울 개수, 방향, 위치
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int W, H;
    cin >> W >> H;
    vector<vector<int>> map(H, vector<int>(W, INT_MAX));
    vector<vector<vector<bool>>> isVisted(H, vector<vector<bool>>(W, vector<bool>(4)));
    priority_queue<ppp, vector<ppp>, greater<ppp>> pq;
    pii end;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
        {
            char c;
            cin >> c;
            if (c == '*')
                map[i][j] = -1;
            else if (c == 'C')
            {
                if (pq.empty())
                {
                    pq.push({{0, -1}, {i, j}});
                    map[i][j] = 0;
                    isVisted[i][j][0] = isVisted[i][j][1] = isVisted[i][j][2] = isVisted[i][j][3] = true;
                }
                else
                    end = {i, j};
            }
        }
    while (!pq.empty())
    {
        ppp cur = pq.top();
        pq.pop();
        int y = cur.second.first, x = cur.second.second, mirror = cur.first.first;
        if (map[y][x] < mirror)
            continue;
        for (int dir = 0; dir < 4; ++dir)
        {
            int weight = cur.first.second == dir ? 0 : 1, nextMirror = mirror + weight;
            int ny = y + dy[dir], nx = x + dx[dir];

            ppp next = {{nextMirror, dir}, {ny, nx}};
            if (ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx] < nextMirror || (isVisted[ny][nx][dir] && map[ny][nx] == nextMirror))
                continue;
            isVisted[ny][nx][dir] = true;
            map[ny][nx] = nextMirror;
            if (ny == end.first && nx == end.second)
                break;
            pq.push(next);
        }
    }
    cout << map[end.first][end.second] - 1;
    return 0;
}