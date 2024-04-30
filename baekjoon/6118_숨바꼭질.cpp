#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, idx, len, cnt;
vector<bool> isVisited;
vector<vector<int>> graph;
queue<int> q;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    graph = vector<vector<int>>(N + 1, vector<int>());
    isVisited = vector<bool>(N + 1);
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    q.push(1);
    isVisited[1] = true;

    while (true)
    {
        idx = 50000;
        cnt = q.size();

        for (int i = 0; i < cnt; ++i)
        {
            int cur = q.front();
            q.pop();

            idx = min(idx, cur);

            for (int next : graph[cur])
            {
                if (isVisited[next])
                {
                    continue;
                }

                isVisited[next] = true;
                q.push(next);
            }
        }

        if (q.empty())
        {
            break;
        }

        ++len;
    }

    cout << idx << " " << len << " " << cnt;
    return 0;
}