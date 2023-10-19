#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, start, end, m;
    cin >> n >> start >> end >> m;
    vector<vector<int>> map(n + 1, vector<int>());
    vector<bool> isVisted(n + 1);
    queue<pair<int, int>> bfs;
    while (m--)
    {
        int p, c;
        cin >> p >> c;
        map[p].push_back(c);
        map[c].push_back(p);
    }
    bfs.push({start, 0});
    isVisted[start] = true;
    while (!bfs.empty())
    {
        auto cur = bfs.front();
        if (end == cur.first)
            break;
        bfs.pop();
        for (int m : map[cur.first])
        {
            if (isVisted[m])
                continue;
            isVisted[m] = true;
            bfs.push({m, cur.second + 1});
        }
    }
    if (!bfs.empty())
        cout << bfs.front().second;
    else
        cout << -1;
    return 0;
}