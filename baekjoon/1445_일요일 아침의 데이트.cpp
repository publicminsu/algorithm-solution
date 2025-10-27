#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;
using piiii = pair<pii, pii>;

int N, M;
char map[50][50];
pii S;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool isVisited[50][50];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];

            switch (map[i][j])
            {
            case 'S':
                S = {i, j};
                map[i][j] = '.';
                break;
            }
        }
    }
}

bool isOut(pii pos)
{
    return pos.first < 0 || pos.second < 0 || pos.first >= N || pos.second >= M;
}

bool checkTrash(pii pos)
{
    if (isOut(pos))
    {
        return false;
    }

    return map[pos.first][pos.second] == 'g';
}

void dijkstra()
{
    priority_queue<piiii, vector<piiii>, greater<piiii>> pq;

    pq.push({{0, 0}, S});

    isVisited[S.first][S.second] = true;

    while (!pq.empty())
    {
        piiii curNode = pq.top();
        pii curCnt = curNode.first;
        pii curPos = curNode.second;
        pq.pop();

        if (map[curPos.first][curPos.second] == 'F')
        {
            cout << curCnt.first << " " << curCnt.second;
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            pii nextPos = {curPos.first + dy[i], curPos.second + dx[i]};
            pii nextCnt = curCnt;

            if (isOut(nextPos) || isVisited[nextPos.first][nextPos.second])
            {
                continue;
            }

            isVisited[nextPos.first][nextPos.second] = true;

            if (checkTrash(nextPos))
            {
                ++nextCnt.first;
            }
            else if (map[nextPos.first][nextPos.second] == '.')
            {
                bool hasTrash = false;

                for (int j = 0; j < 4; ++j)
                {
                    pii nearPos = {nextPos.first + dy[j], nextPos.second + dx[j]};

                    if (checkTrash(nearPos))
                    {
                        hasTrash = true;
                    }
                }

                if (hasTrash)
                {
                    ++nextCnt.second;
                }
            }

            pq.push({nextCnt, nextPos});
        }
    }
}

int main()
{
    input();
    dijkstra();
    return 0;
}