#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define LIMIT 1001
int times[LIMIT], indegree[LIMIT], totalTimes[LIMIT];
vector<int> graph[LIMIT];
int solve()
{
    int N, K, W;
    cin >> N >> K;

    for (int i = 1; i <= N; ++i)
    {
        cin >> times[i];
        graph[i].clear();
        totalTimes[i] = 0;
    }

    while (K--)
    {
        int X, Y;
        cin >> X >> Y;
        graph[X].push_back(Y);
        ++indegree[Y];
    }

    cin >> W;

    queue<int> q;

    for (int i = 1; i <= N; ++i)
    {
        if (indegree[i] == 0) // 진입 차수가 0인 것
        {
            q.push(i);
            totalTimes[i] = times[i];
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            totalTimes[next] = max(totalTimes[next], totalTimes[cur] + times[next]); // 가장 오래 걸린 건물의 시간으로 갱신

            if (--indegree[next] == 0) // 진입 차수가 0인 것
            {
                q.push(next);
            }
        }
    }

    return totalTimes[W];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        cout << solve() << "\n";
    }
    return 0;
}