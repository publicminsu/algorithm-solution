#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using pii = pair<int, int>;

int N, M;
vector<int> map[100000];
queue<pii> q;
bool isVisited[100000];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    while (M--)
    {
        int x, y;
        cin >> x >> y;

        map[x].push_back(y);
    }
}

int solve()
{
    q.push({1, 0});

    while (!q.empty())
    {
        pii curNode = q.front();
        q.pop();

        for (int nextIdx : map[curNode.first])
        {
            int nextDist = curNode.second + 1;

            if (nextIdx == N)
            {
                return nextDist;
            }

            if (isVisited[nextIdx])
            {
                continue;
            }

            isVisited[nextIdx] = true;

            q.push({nextIdx, nextDist});
        }
    }

    return -1;
}

int main()
{
    input();
    cout << solve();
    return 0;
}