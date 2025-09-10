#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, k, costSum;
int A[10001];
vector<int> graph[10001];
bool isVisited[10001];
queue<int> q;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> k;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    while (M--)
    {
        int v, w;
        cin >> v >> w;
        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    for (int i = 1; i <= N; ++i)
    {
        if (isVisited[i])
        {
            continue;
        }

        q.push(i);
        int cost = A[i];

        while (!q.empty())
        {
            int curFriend = q.front();
            q.pop();

            for (int nextFriend : graph[curFriend])
            {
                if (isVisited[nextFriend])
                {
                    continue;
                }

                isVisited[nextFriend] = true;
                q.push(nextFriend);

                cost = min(cost, A[nextFriend]);
            }
        }

        costSum += cost;
    }

    if (costSum <= k)
    {
        cout << costSum;
    }
    else
    {
        cout << "Oh no";
    }
    return 0;
}