#include <iostream>
#include <queue>
using namespace std;

using pii = pair<int, int>;
using piii = pair<int, pii>;

int M, N, P, HP, playerCount;
char map[1001][1001];
bool isVisited[26][1001][1001];
bool isCounted[26];
pii playerPos[26];
int damages[26];
queue<piii> q;
int dps;
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> M >> N >> P;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];

            if (map[i][j] >= 'a' && map[i][j] <= 'z')
            {
                playerPos[map[i][j] - 'a'] = {i, j};
                map[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < P; ++i)
    {
        char id;
        int dps;
        cin >> id >> dps;

        id -= 'a';

        damages[id] = dps;
        pii pos = playerPos[id];

        isVisited[id][pos.first][pos.second] = true;

        q.push({id, pos});
    }

    cin >> HP;
}

void bfs()
{
    while (!q.empty())
    {
        HP -= dps;

        int size = q.size();

        for (int i = 0; i < size; ++i)
        {
            piii curNode = q.front();
            q.pop();

            pii pos = curNode.second;

            int id = curNode.first;
            int y = pos.first;
            int x = pos.second;

            if (isCounted[id])
            {
                continue;
            }

            for (int j = 0; j < 4; ++j)
            {
                if (isCounted[id])
                {
                    break;
                }

                int ny = y + dy[j];
                int nx = x + dx[j];

                if (ny < 0 || nx < 0 || ny >= M || nx >= N)
                {
                    continue;
                }

                if (isVisited[id][ny][nx])
                {
                    continue;
                }

                isVisited[id][ny][nx] = true;

                switch (map[ny][nx])
                {
                case 'X':
                    break;
                case 'B':
                    isCounted[id] = true;

                    ++playerCount;
                    HP -= damages[id];
                    dps += damages[id];
                    break;
                default:
                    q.push({id, {ny, nx}});
                    break;
                }
            }
        }

        if (HP <= 0)
        {
            break;
        }
    }

    cout << playerCount;
}

int main()
{
    input();
    bfs();
    return 0;
}