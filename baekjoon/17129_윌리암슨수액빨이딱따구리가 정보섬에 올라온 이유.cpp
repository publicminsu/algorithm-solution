#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int n, m;
int map[3000][3000];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
queue<pii> q;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c;
            cin >> c;

            if (c == '2')
            {
                q.push({i, j});
                map[i][j] = -1;
            }
            else
            {
                map[i][j] = c - '0';
            }
        }
    }

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        const int &curValue = map[cur.first][cur.second];

        for (int i = 0; i < 4; ++i)
        {
            pii next = {cur.first + dy[i], cur.second + dx[i]};

            if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m)
            {
                continue;
            }

            int &nextValue = map[next.first][next.second];
            if (nextValue < 0 || nextValue == 1)
            {
                continue;
            }

            if (nextValue > 1)
            {
                cout << "TAK\n"
                     << -curValue;
                return 0;
            }

            nextValue = curValue - 1;

            q.push(next);
        }
    }

    cout << "NIE";
    return 0;
}