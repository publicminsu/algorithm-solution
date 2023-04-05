#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M;
    cin >> N;
    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> rumor(N + 1);
    vector<int> visted(N + 1, -1);
    queue<int> q;
    for (int i = 1, j; i <= N; ++i)
    {
        while (true)
        {
            cin >> j;
            if (!j)
                break;
            graph[i].push_back(j);
        }
    }
    cin >> M;
    while (M--)
    {
        int i;
        cin >> i;
        visted[i] = 0;
        q.push(i);
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur])
        {
            if (visted[next] == -1 && ((++rumor[next]) << 1) >= graph[next].size())
            {
                visted[next] = visted[cur] + 1;
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= N; ++i)
        cout << visted[i] << " ";
    return 0;
}