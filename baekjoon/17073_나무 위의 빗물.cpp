#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout.precision(6);
    int N, W, cnt = 0;
    double ret;
    cin >> N >> W;
    vector<vector<int>> graph(N + 1, vector<int>());
    vector<bool> visted(N + 1);
    queue<int> q;
    for (int i = 1, U, V; i < N; ++i)
    {
        cin >> U >> V;
        graph[U].push_back(V);
        graph[V].push_back(U);
    }
    visted[1] = true;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front(), size = 0;
        q.pop();
        for (int next : graph[cur])
            if (!visted[next])
                ++size;
        if (size)
        {
            for (int next : graph[cur])
            {
                if (visted[next])
                    continue;
                visted[next] = true;
                q.push(next);
            }
        }
        else
        {
            ++cnt;
        }
    }
    ret = (double)W / cnt;
    cout << fixed << ret;
    return 0;
}