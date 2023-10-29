#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INIT 987654321
vector<vector<char>> map;
vector<vector<int>> dist;
int N;
struct node
{
    int y, x;
    bool isCol; // 좌표, 가로 세로 여부
};
node startNode, endNode;
queue<node> q;
void check(node cur) // 가까운 좌표부터 줄 단위로 탐색
{
    if (cur.isCol) // 세로인가?
    {
        for (int i = cur.y - 1; i >= 0; --i)
        {
            if (map[i][cur.x] == '*')
            {
                break;
            }

            if (dist[cur.y][i] != INIT && dist[i][cur.x] < dist[cur.y][cur.x] + 1) // 이미 방문했고 더 많은 값을 필요로 하면
            {
                continue;
            }

            dist[i][cur.x] = dist[cur.y][cur.x] + 1;
            if (map[i][cur.x] == '!') // 거울 설치 가능 여부
            {
                q.push({i, cur.x, false});
            }
        }
        for (int i = cur.y + 1; i < N; ++i)
        {
            if (map[i][cur.x] == '*')
            {
                break;
            }

            if (dist[cur.y][i] != INIT && dist[i][cur.x] < dist[cur.y][cur.x] + 1)
            {
                continue;
            }

            dist[i][cur.x] = dist[cur.y][cur.x] + 1;
            if (map[i][cur.x] == '!')
            {
                q.push({i, cur.x, false});
            }
        }
    }
    else
    {
        for (int i = cur.x - 1; i >= 0; --i)
        {
            if (map[cur.y][i] == '*')
            {
                break;
            }

            if (dist[cur.y][i] != INIT && dist[cur.y][i] < dist[cur.y][cur.x] + 1)
            {
                continue;
            }

            dist[cur.y][i] = dist[cur.y][cur.x] + 1;
            if (map[cur.y][i] == '!')
            {
                q.push({cur.y, i, true});
            }
        }
        for (int i = cur.x + 1; i < N; ++i)
        {
            if (map[cur.y][i] == '*')
            {
                break;
            }

            if (dist[cur.y][i] != INIT && dist[cur.y][i] < dist[cur.y][cur.x] + 1)
            {
                continue;
            }

            dist[cur.y][i] = dist[cur.y][cur.x] + 1;
            if (map[cur.y][i] == '!')
            {
                q.push({cur.y, i, true});
            }
        }
    }
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    dist = vector<vector<int>>(N, vector<int>(N, INIT));
    map = vector<vector<char>>(N, vector<char>(N));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];

            if (map[i][j] == '#')
            {
                if (startNode.isCol) // 시작 값 초기화했는가?
                {
                    endNode = {i, j, 0};
                }
                else
                {
                    startNode = {i, j, 1};
                }
            }
        }
    }
}
void solve()
{
    dist[startNode.y][startNode.x] = -1;

    check({startNode.y, startNode.x, 0});
    check({startNode.y, startNode.x, 1});

    while (!q.empty())
    {
        node cur = q.front();
        q.pop();

        check(cur);
    }
}
int main()
{
    input();
    solve();

    cout << dist[endNode.y][endNode.x];
    return 0;
}