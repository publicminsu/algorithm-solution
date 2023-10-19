#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m)), ret(n, vector<int>(m));
    queue<pii> q;
    pii start;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                start.first = i, start.second = j;
                map[i][j] = 0;
            }
        }
    q.push(start);
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int ny = cur.first + dy[i], nx = cur.second + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || !map[ny][nx])
                continue;
            map[ny][nx] = 0;
            ret[ny][nx] = ret[cur.first][cur.second] + 1;
            q.push({ny, nx});
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (map[i][j] == 1)
                ret[i][j] = -1;
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}