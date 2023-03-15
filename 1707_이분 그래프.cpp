#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int vState[20001], K, V, E;
vector<int> edge[20001];
bool bfs()
{
    queue<int> q;
    for (int i = 1; i <= V; ++i)
    {
        if (vState[i])
            continue;
        q.push(i);
        vState[i] = 1;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int j : edge[cur])
            {
                if (vState[j])
                {
                    if (vState[j] == vState[cur])
                    {
                        return false;
                    }
                    continue;
                }
                if (vState[cur] == 1)
                {
                    vState[j] = 2;
                }
                else
                {
                    vState[j] = 1;
                }
                q.push(j);
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> K;
    while (K--)
    {
        cin >> V >> E;
        for (int i = 1; i <= V; ++i)
        {
            edge[i].clear();
            vState[i] = 0;
        }
        while (E--)
        {
            int n1, n2;
            cin >> n1 >> n2;
            edge[n1].push_back(n2);
            edge[n2].push_back(n1);
        }
        cout << (bfs() ? "YES" : "NO") << "\n";
    }
}