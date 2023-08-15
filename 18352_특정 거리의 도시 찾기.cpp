#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, K, X;
vector<int> ret, isVisited;
vector<vector<int>> graph;
queue<int> q;
void bfs()
{
    q.push(X);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur])
        {
            if (isVisited[next] != -1)
                continue;
            isVisited[next] = isVisited[cur] + 1;
            q.push(next);
            if (isVisited[next] == K)
                ret.push_back(next);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K >> X;
    graph = vector<vector<int>>(N + 1, vector<int>());
    isVisited = vector<int>(N + 1, -1);
    isVisited[X] = 0;
    while (M--)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }
    bfs();
    if (ret.empty())
    {
        cout << -1;
        return 0;
    }
    sort(ret.begin(), ret.end());
    for (int i : ret)
        cout << i << "\n";
    return 0;
}