#include <iostream>
#include <queue>
using namespace std;
int map[100001], ret = 0, N, K;
queue<pair<int, int>> bfs;
void push(int num, int cost)
{
    if (num < 0 || num > 100000)
        return;
    if (!map[num])
        map[num] = cost;
    if (map[num] == cost)
    {
        if (num == K)
            ++ret;
        else
            bfs.push({num, cost});
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    if (N == K)
    {
        cout << 0 << "\n"
             << 1;
        return 0;
    }
    bfs.push({N, 0});
    while (!bfs.empty())
    {
        pair<int, int> cur = bfs.front();
        bfs.pop();
        int n1, n2, n3, cost = cur.second + 1;
        n1 = cur.first + 1;
        n2 = cur.first - 1;
        n3 = cur.first << 1;
        push(n1, cost);
        push(n2, cost);
        push(n3, cost);
    }
    cout << map[K] << "\n"
         << ret;
    return 0;
}