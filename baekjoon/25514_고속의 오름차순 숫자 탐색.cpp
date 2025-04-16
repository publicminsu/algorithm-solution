#include <iostream>
#include <queue>
using namespace std;
#define INF 987654321

struct node
{
    int y, x, cnt, num;
};

int board[5][5];
int r, c;
int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
int cntBoard[5][5][7];
queue<node> q;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> board[i][j];

            for (int k = 0; k < 7; ++k)
            {
                cntBoard[i][j][k] = INF;
            }
        }
    }

    cin >> r >> c;
}

int bfs()
{
    auto isOut = [](int i)
    {
        return i < 0 || i >= 5;
    };

    auto isOutNode = [&](node n)
    {
        return isOut(n.x) || isOut(n.y) || board[n.y][n.x] == -1;
    };

    q.push({r, c, 0, 1});

    while (!q.empty())
    {
        node curNode = q.front();
        q.pop();

        if (board[curNode.y][curNode.x] == curNode.num)
        {
            ++curNode.num;

            if (curNode.num == 7)
            {
                return curNode.cnt;
            }
        }

        int &cnt = cntBoard[curNode.y][curNode.x][curNode.num];

        if (cnt != INF)
        {
            continue;
        }

        cnt = curNode.cnt;

        for (int i = 0; i < 4; ++i)
        {
            int ny = curNode.y + dy[i];
            int nx = curNode.x + dx[i];

            node nextNode = {ny, nx, curNode.cnt + 1, curNode.num};

            if (isOutNode(nextNode))
            {
                continue;
            }

            q.push(nextNode);

            int dist = -1;

            for (int j = 1; j < 5; ++j)
            {
                ny = curNode.y + dy[i] * j;
                nx = curNode.x + dx[i] * j;

                nextNode = {ny, nx, curNode.cnt + 1, curNode.num};

                if (isOutNode(nextNode))
                {
                    break;
                }

                dist = j;

                if (board[ny][nx] == 7)
                {
                    break;
                }
            }

            if (dist != -1)
            {
                ny = curNode.y + dy[i] * dist;
                nx = curNode.x + dx[i] * dist;

                nextNode = {ny, nx, curNode.cnt + 1, curNode.num};

                q.push(nextNode);
            }
        }
    }

    return -1;
}

int main()
{
    input();
    cout << bfs();
    return 0;
}