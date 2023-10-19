#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>> adj;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, start, end, cost;
    cin >> N >> M;
    vector<vector<pii>> adj(N + 1, vector<pii>());
    vector<bool> visted(N + 1);
    for (int i = 1; i < N; ++i)
    {
        cin >> start >> end >> cost;
        adj[start].push_back({end, cost});
        adj[end].push_back({start, cost});
    }
    for (int i = 0; i < M; ++i)
    {
        cin >> start >> end;
        queue<pii> q;
        fill(visted.begin(), visted.end(), false);
        q.push({start, 0});
        while (!q.empty())
        {
            pii cur = q.front();
            q.pop();
            if (cur.first == end)
            {
                cout << cur.second << "\n";
                break;
            }
            for (pii next : adj[cur.first])
            {
                if (visted[next.first])
                    continue;
                visted[next.first] = true;
                q.push({next.first, cur.second + next.second});
            }
        }
    }
    return 0;
}