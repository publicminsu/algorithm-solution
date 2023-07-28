#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, start, end, cost;
    cin >> N >> M;
    vector<vector<pii>> graph(N + 1, vector<pii>());
    vector<int> isVisited(N + 1, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    while (M--)
    {
        cin >> start >> end >> cost;
        graph[start].push_back({end, cost});
    }
    cin >> start >> end;
    isVisited[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        pii cur = pq.top();
        if (cur.second == end)
        {
            cout << cur.first;
            return 0;
        }
        pq.pop();
        for (pii next : graph[cur.second])
        {
            int nextVal = cur.first + next.second;
            if (isVisited[next.first] != -1 && nextVal >= isVisited[next.first])
                continue;
            isVisited[next.first] = nextVal;
            pq.push({nextVal, next.first});
        }
    }
}