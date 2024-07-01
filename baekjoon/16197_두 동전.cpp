#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<vector<bool>> board;
int N, M;

struct coin
{
    int y, x;

    const coin operator+(const coin &other) const
    {
        return {y + other.y, x + other.x};
    }

    const bool operator==(const coin &other) const
    {
        return y == other.y && x == other.x;
    }

    const bool operator<(const coin &other) const
    {
        if (other.y == y)
        {
            return x < other.x;
        }
        else
        {
            return y < other.y;
        }
    }

    const bool isOut() const
    {
        return y < 0 || x < 0 || y >= N || x >= M;
    }

    void adjustPos(const coin &d)
    {
        if (board[y][x])
        {
            y -= d.y;
            x -= d.x;
        }
    }
} dir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct node
{
    coin coin1;
    coin coin2;

    const bool operator<(const node other) const
    {
        if (coin1 == other.coin1)
        {
            return coin2 < other.coin2;
        }
        else
        {
            return coin1 < other.coin1;
        }
    }
};

void bfs(coin curCoin1, coin curCoin2)
{
    queue<node> q = queue<node>();
    map<node, int> dist = map<node, int>();

    node start = {curCoin1, curCoin2};
    q.push(start);
    dist[start] = 1;

    while (!q.empty())
    {
        node cur = q.front();
        q.pop();

        for (const coin &d : dir)
        {
            coin nextCoin1 = cur.coin1 + d;
            coin nextCoin2 = cur.coin2 + d;

            if (nextCoin1.isOut() || nextCoin2.isOut())
            {
                if (nextCoin1.isOut() && nextCoin2.isOut())
                {
                    continue;
                }

                if (dist[cur] > 10)
                {
                    break;
                }

                cout << dist[cur];
                return;
            }

            nextCoin1.adjustPos(d);
            nextCoin2.adjustPos(d);

            if (nextCoin1 == nextCoin2)
            {
                continue;
            }

            node next = {nextCoin1, nextCoin2};

            if (dist[next] != 0)
            {
                continue;
            }

            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }

    cout << -1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    board = vector<vector<bool>>(N, vector<bool>(M));

    coin coin1 = {-1}, coin2;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            char c;
            cin >> c;

            if (c == '#')
            {
                board[i][j] = true;
            }
            else if (c == 'o')
            {
                coin newCoin{i, j};

                if (coin1.y == -1)
                {
                    coin1 = newCoin;
                }
                else
                {
                    coin2 = newCoin;
                }
            }
        }
    }

    bfs(coin1, coin2);
    return 0;
}