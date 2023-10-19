#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
bool graph[501][501];
int inDegree[501], nums[501], n, m, a, b;
stack<int> ret;
void input()
{
    memset(graph, false, sizeof(graph));
    memset(inDegree, 0, sizeof(inDegree));
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> nums[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = n; j > i; --j)
        {
            ++inDegree[nums[i]];
            graph[nums[j]][nums[i]] = true;
        }
    }
    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        if (graph[b][a])
        {
            swap(a, b);
        }
        --inDegree[b];
        ++inDegree[a];
        graph[b][a] = true;
        graph[a][b] = false;
    }
}
void solve()
{
    ret = stack<int>();
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (!inDegree[i])
            q.push(i);
    for (int i = 1; i <= n; ++i)
    {
        if (q.empty())
        {
            cout << "IMPOSSIBLE"
                 << "\n";
            return;
        }
        int cur = q.front();
        q.pop();
        ret.push(cur);
        for (int j = 1; j <= n; ++j)
        {
            if (graph[cur][j] && !(--inDegree[j]))
                q.push(j);
        }
    }
    while (!ret.empty())
    {
        cout << ret.top() << " ";
        ret.pop();
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        input();
        solve();
    }
}