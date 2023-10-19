#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int dx[] = {2, 2, 1, 1, -1, -1, -2, -2}, dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
int map[301][301];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    queue<pair<int, int>> bfs;
    while (T--)
    {
        memset(map, 0, sizeof(map));
        bfs = queue<pair<int, int>>();
        int l;
        cin >> l;
        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY;
        bfs.push({startX, startY});
        while (!bfs.empty())
        {
            auto cur = bfs.front();
            if (cur.first == endX && cur.second == endY)
                break;
            bfs.pop();
            for (int i = 0; i < 8; ++i)
            {
                pair<int, int> next = {cur.first + dx[i], cur.second + dy[i]};
                if (next.first < 0 || next.second < 0 || next.first >= l || next.second >= l)
                    continue;
                if (map[next.first][next.second])
                    continue;
                map[next.first][next.second] = map[cur.first][cur.second] + 1;
                bfs.push(next);
            }
        }
        cout << map[bfs.front().first][bfs.front().second] << "\n";
    }
    return 0;
}