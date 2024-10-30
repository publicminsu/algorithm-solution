#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node
{
    char x;
    int y;

    vector<char> prevX;
    vector<int> prevY;
};

int dy[] = {1, 1, -1, -1};
int dx[] = {1, -1, 1, -1};
bool isVisited[9][9];

int T;
queue<node> q;
char sX, eX;
int sY, eY;

bool bfs()
{
    memset(isVisited, false, sizeof(isVisited));
    q = queue<node>();

    q.push({sX, sY, {sX}, {sY}});

    while (!q.empty())
    {
        node cur = q.front();
        q.pop();

        if (cur.x == eX && cur.y == eY)
        {
            cout << cur.prevX.size() - 1 << " ";
            for (int i = 0; i < cur.prevX.size(); ++i)
            {
                cout << cur.prevX[i] << " " << cur.prevY[i] << " ";
            }
            return true;
        }

        if (cur.prevX.size() == 5 || isVisited[cur.x - 'A'][cur.y])
        {
            continue;
        }
        isVisited[cur.x - 'A'][cur.y] = true;

        for (int i = 1; i < 8; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                char nX = cur.x + dx[j] * i;
                int nY = cur.y + dy[j] * i;
                vector<char> prevX = cur.prevX;
                vector<int> prevY = cur.prevY;

                prevX.push_back(nX);
                prevY.push_back(nY);

                node next = {nX, nY, prevX, prevY};
                if (next.x < 'A' || next.y < 1 || next.x > 'H' || next.y > 8)
                {
                    continue;
                }
                q.push(next);
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> sX >> sY >> eX >> eY;
        if (!bfs())
        {
            cout << "Impossible";
        }
        cout << "\n";
    }
    return 0;
}