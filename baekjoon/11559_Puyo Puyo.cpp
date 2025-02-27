#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

bool isVisited[12][6];
char map[12][6];
int answer;
vector<pii> visitedNodes;
queue<pii> q;

pii d[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            cin >> map[i][j];
        }
    }

    visitedNodes.reserve(72);
}

bool remove()
{
    bool isFind = false;

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (map[i][j] == '.')
            {
                continue;
            }

            char target = map[i][j];
            q.push({i, j});
            visitedNodes.push_back({i, j});
            isVisited[i][j] = true;

            while (!q.empty())
            {
                pii cur = q.front();
                q.pop();

                for (pii p : d)
                {
                    pii next = {cur.first + p.first, cur.second + p.second};

                    if (next.first < 0 || next.second < 0 || next.first >= 12 || next.second >= 6)
                    {
                        continue;
                    }

                    if (target != map[next.first][next.second])
                    {
                        continue;
                    }

                    if (isVisited[next.first][next.second])
                    {
                        continue;
                    }

                    isVisited[next.first][next.second] = true;
                    visitedNodes.push_back(next);
                    q.push(next);
                }
            }

            if (visitedNodes.size() >= 4)
            {
                isFind = true;

                for (pii visitedNode : visitedNodes)
                {
                    map[visitedNode.first][visitedNode.second] = '.';
                }
            }

            visitedNodes.clear();
        }
    }

    return isFind;
}

void move()
{
    for (int i = 10; i >= 0; --i)
    {
        for (int j = 0; j < 6; ++j)
        {
            char target = map[i][j];

            if (target)
            {
                for (int k = i + 1; k >= 0; ++k)
                {
                    if (map[k][j] != '.')
                    {
                        map[i][j] = '.';
                        map[k - 1][j] = target;
                        break;
                    }
                }
            }
        }
    }
}

void solve()
{
    while (remove())
    {
        move();
        ++answer;
        memset(isVisited, false, sizeof(isVisited));
    }

    cout << answer;
}

int main()
{
    input();
    solve();
    return 0;
}