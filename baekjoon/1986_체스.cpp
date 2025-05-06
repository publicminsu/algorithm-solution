#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;
#define OBSTACLE_TYPE 1
#define MOVE_TYPE 2

int n, m;
int map[1001][1001];
queue<pii> queens, knights, pawns;
pii knightMoves[] = {{2, 1}, {1, 2}, {2, -1}, {-1, 2}, {-2, 1}, {1, -2}, {-2, -1}, {-1, -2}};
pii queenMoves[] = {{1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};

void input()
{
    auto inputQ = [](queue<pii> &q)
    {
        int size;
        cin >> size;
        while (size--)
        {
            pii pos;
            cin >> pos.first >> pos.second;
            q.push(pos);
        }
    };

    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    inputQ(queens);
    inputQ(knights);
    inputQ(pawns);
}

void solve()
{
    auto paint = [](const pii &p, int type = OBSTACLE_TYPE)
    {
        if (map[p.first][p.second] == OBSTACLE_TYPE)
        {
            return;
        }

        map[p.first][p.second] = type;
    };

    auto pop = [&](queue<pii> &q)
    {
        pii value = q.front();
        q.pop();

        paint(value);

        return value;
    };

    auto isOut = [](const pii &p)
    {
        return p.first < 1 || p.second < 1 || p.first > n || p.second > m;
    };

    auto add = [](const pii &x, const pii &y)
    {
        return make_pair(x.first + y.first, x.second + y.second);
    };

    while (!pawns.empty())
    {
        pop(pawns);
    }

    while (!knights.empty())
    {
        pii knight = pop(knights);

        for (const pii &move : knightMoves)
        {
            pii pos = add(knight, move);

            if (isOut(pos))
            {
                continue;
            }

            paint(pos, MOVE_TYPE);
        }
    }

    while (!queens.empty())
    {
        pii queen = pop(queens);

        for (const pii &move : queenMoves)
        {
            for (int i = 1;; ++i)
            {
                pii p = {move.first * i, move.second * i};
                pii pos = add(queen, p);

                if (isOut(pos) || map[pos.first][pos.second] == OBSTACLE_TYPE)
                {
                    break;
                }

                paint(pos, MOVE_TYPE);
            }
        }
    }

    int cnt = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (!map[i][j])
            {
                ++cnt;
            }
        }
    }

    cout << cnt;
}

int main()
{
    input();
    solve();
    return 0;
}