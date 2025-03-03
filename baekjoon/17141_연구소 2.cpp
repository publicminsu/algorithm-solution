#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

using pii = pair<int, int>;
#define INF 987654321

int N, M, answer = INF;
int map[51][51];
int count[51][51];
vector<pii> virus;
pii dir[]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];

            if (map[i][j] == 2)
            {
                virus.push_back({i, j});
                map[i][j] = 0;
            }
        }
    }
}

void bfs(queue<pii> q)
{
    auto isOutInternal = [](int x)
    {
        return x < 0 || x >= N;
    };
    auto isOut = [&](pii p)
    {
        return isOutInternal(p.first) || isOutInternal(p.second);
    };

    memset(count, 0, sizeof(count));

    for (int i = 0; i < q.size(); ++i)
    {
        pii cur = q.front();
        q.pop();

        count[cur.first][cur.second] = 1;

        q.push(cur);
    }

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        for (pii d : dir)
        {
            pii next = {cur.first + d.first, cur.second + d.second};

            int &nextCount = count[next.first][next.second];

            if (isOut(next) || nextCount || map[next.first][next.second])
            {
                continue;
            }

            nextCount = count[cur.first][cur.second] + 1;

            if (nextCount >= answer)
            {
                return;
            }

            q.push(next);
        }
    }

    int maxCount = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!count[i][j] && !map[i][j])
            {
                return;
            }

            maxCount = max(maxCount, count[i][j]);
        }
    }

    answer = min(answer, maxCount);
}

void comb(int index, queue<pii> q)
{
    if (q.size() == M)
    {
        bfs(q);
        return;
    }

    if (index == virus.size())
    {
        return;
    }

    comb(index + 1, q);
    q.push(virus[index]);
    comb(index + 1, q);
}

int main()
{
    input();
    comb(0, queue<pii>());

    if (answer == INF)
    {
        cout << -1;
    }
    else
    {
        cout << answer - 1;
    }

    return 0;
}