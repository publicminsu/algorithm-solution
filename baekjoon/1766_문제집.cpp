#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> inDegree;
vector<vector<int>> graph;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    inDegree = vector<int>(N + 1);
    graph = vector<vector<int>>(N + 1, vector<int>());

    while (M--)
    {
        int A, B;
        cin >> A >> B;

        ++inDegree[B]; // 진입 차수
        graph[A].push_back(B);
    }
}
void solve()
{
    priority_queue<int, vector<int>, greater<int>> pq; // 값이 낮은 것이 우선

    for (int i = 1; i <= N; ++i)
    {
        if (!inDegree[i]) // 진입 차수가 0인 노드
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        cout << cur << " ";

        for (int next : graph[cur])
        {
            if (--inDegree[next] == 0) // 진입 차수가 0이 되는 노드
            {
                pq.push(next);
            }
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}