#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;
using pipii = pair<int, pii>;
int N, M, Tg, Tb, X, B;
char map[1001][1001];
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> Tg >> Tb >> X >> B;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];

            if (map[i][j] == '*')
            {
                pq.push({0, {i, j}});
            }
        }
    }

    while (!pq.empty())
    {
        pipii cur = pq.top();
        pq.pop();

        for (int i = 0; i < 4; ++i)
        {
            pii nextPos = cur.second;
            nextPos.first += dy[i];
            nextPos.second += dx[i];

            if (nextPos.first < 0 || nextPos.second < 0 || nextPos.first >= N || nextPos.second >= M)
            {
                continue;
            }

            char &value = map[nextPos.first][nextPos.second];

            switch (value)
            {
            case '#':
            {
                int nextTime = cur.first + Tb + 1;
                if (nextTime <= Tg)
                {
                    value = '*';

                    if (nextTime < Tg)
                    {
                        pq.push({nextTime, nextPos});
                    }
                }
                else
                {
                    value = '-';
                }
            }
            break;
            case '.':
            {
                int nextTime = cur.first + 1;
                if (nextTime <= Tg)
                {
                    value = '*';

                    if (nextTime < Tg)
                    {
                        pq.push({nextTime, nextPos});
                    }
                }
            }
            break;
            default:
                break;
            }
        }
    }

    bool isFind = false;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            switch (map[i][j])
            {
            case '#':
            case '-':
            case '.':
                isFind = true;
                cout << (i + 1) << " " << (j + 1) << "\n";
                break;
            default:
                break;
            }
        }
    }

    if (!isFind)
    {
        cout << -1;
    }
    return 0;
}