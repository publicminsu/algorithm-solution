#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int V, E, sum = 0;
    cin >> V >> E;
    vector<bool> visted(V + 1);
    vector<vector<pair<int, int>>> map(V + 1, vector<pair<int, int>>());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while (E--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        map[A].push_back({B, C});
        map[B].push_back({A, C});
    }
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (visted[cur.second])
            continue;
        visted[cur.second] = true;
        sum += cur.first;
        for (auto next : map[cur.second])
        {
            if (visted[next.first])
                continue;
            pq.push({next.second, next.first});
        }
    }
    cout << sum;
    return 0;
}