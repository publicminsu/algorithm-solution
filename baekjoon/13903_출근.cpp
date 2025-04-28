#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

#define INF 987654321
#define INIT_VALUE -1

int R, C, N;
bool map[1001][1001];
int cnt[1001][1001];
int dy[10], dx[10];
queue<pii> q;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> map[i][j];
            cnt[i][j] = INIT_VALUE;
        }
    }

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> dy[i] >> dx[i];
    }
}

void bfs()
{
    for (int i = 0; i < C; ++i)
    {
        if (map[0][i])
        {
            q.push({0, i});
            cnt[0][i] = 0;
        }
    }

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < N; ++i)
        {
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if (ny < 0 || nx < 0 || ny >= R || nx >= C)
            {
                continue;
            }

            int &value = cnt[ny][nx];

            if (!map[ny][nx] || value != -1)
            {
                continue;
            }

            value = cnt[cur.first][cur.second] + 1;

            q.push({ny, nx});
        }
    }
}

int main()
{
    input();
    bfs();

    int answer = INF;

    for (int i = 0; i < C; ++i)
    {
        const int &value = cnt[R - 1][i];
        if (value != INIT_VALUE)
        {
            answer = min(answer, value);
        }
    }

    if (answer == INF)
    {
        answer = -1;
    }

    cout << answer;

    return 0;
}