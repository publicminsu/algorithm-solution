#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, ret = 0;
    cin >> N >> M;
    vector<vector<int>> map(N + 1, vector<int>());
    vector<bool> isVisted(N + 1);
    queue<int> bfs;
    while (M--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        map[n1].push_back(n2);
        map[n2].push_back(n1);
    }
    bfs.push(1);
    isVisted[1] = true;
    while (!bfs.empty())
    {
        int cur = bfs.front();
        bfs.pop();
        for (int next : map[cur])
        {
            if (isVisted[next])
                continue;
            isVisted[next] = true;
            ++ret;
            bfs.push(next);
        }
    }
    cout << ret;
    return 0;
}