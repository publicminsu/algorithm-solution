#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, ret = 0;
    cin >> N >> M;
    vector<vector<int>> map(N + 1);
    vector<bool> visted(N + 1);
    queue<int> bfs;
    for (int i = 0; i < M; ++i)
    {
        int start, end;
        cin >> start >> end;
        map[start].push_back(end);
        map[end].push_back(start);
    }
    for (int i = 1; i <= N; ++i)
    {
        if (visted[i])
            continue;
        visted[i] = true;
        ++ret;
        bfs.push(i);
        while (!bfs.empty())
        {
            int cur = bfs.front();
            bfs.pop();
            for (int j : map[cur])
            {
                if (visted[j])
                    continue;
                visted[j] = true;
                bfs.push(j);
            }
        }
    }
    cout << ret;
}