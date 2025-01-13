#include <iostream>
#include <queue>
using namespace std;
#define MAX_SIZE 1000001
struct node
{
    int dir, cnt, energy;
};
int dx[] = {3, 1, 2};
int abc[3];
int K, answer = MAX_SIZE;
queue<node> q;
bool isVisited[4][MAX_SIZE];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 3; ++i)
    {
        cin >> abc[i];
    }

    cin >> K;

    q.push({0, 0, 0});

    while (!q.empty())
    {
        node cur = q.front();
        q.pop();

        bool &check = isVisited[cur.dir][cur.energy];

        if (check)
        {
            continue;
        }

        check = true;

        for (int i = 0; i < 3; ++i)
        {
            int nextDir = (cur.dir + dx[i]) % 4;
            int nextCnt = cur.cnt + 1;
            int nextEnergy = cur.energy + abc[i];

            if (nextEnergy >= K)
            {
                if (nextEnergy == K && nextDir == 0)
                {
                    answer = min(answer, nextCnt);
                }
                continue;
            }

            node next = {nextDir, nextCnt, nextEnergy};
            q.push(next);
        }
    }

    cout << (answer == MAX_SIZE ? -1 : answer);
    return 0;
}