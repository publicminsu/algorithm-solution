#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;
#define SIZE 1001
#define INF 987654321

int T, N, M;
vector<pii> graph[SIZE];
bool isVisited[SIZE];

int dfs(int cur)
{
    isVisited[cur] = true;

    int sum = 0;

    for (pii nextNode : graph[cur])
    {
        if (isVisited[nextNode.first])
        {
            continue;
        }

        int nextValue = dfs(nextNode.first);

        nextValue = min(nextValue, nextNode.second);

        sum += nextValue;
    }

    return sum == 0 ? INF : sum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N >> M;

        for (int i = 1; i <= N; ++i)
        {
            isVisited[i] = false;
            graph[i].clear();
        }

        for (int i = 0, a, b, d; i < M; ++i)
        {
            cin >> a >> b >> d;

            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }

        cout << (N == 1 ? 0 : dfs(1)) << "\n";
    }
    return 0;
}