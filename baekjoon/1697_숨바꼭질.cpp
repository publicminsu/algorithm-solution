#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int map[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(map, 0x3f, sizeof(map));
    queue<int> bfs;
    int N, K;
    cin >> N >> K;
    bfs.push(N);
    map[N] = 0;
    while (!bfs.empty())
    {
        int cur = bfs.front();
        bfs.pop();
        if (cur == K)
        {
            cout << map[cur];
            exit(0);
        }
        if (cur + 1 <= 100000)
        {
            if (map[cur + 1] > map[cur] + 1)
            {
                map[cur + 1] = map[cur] + 1;
                bfs.push(cur + 1);
            }
        }
        if (cur - 1 >= 0)
        {
            if (map[cur - 1] > map[cur] + 1)
            {
                map[cur - 1] = map[cur] + 1;
                bfs.push(cur - 1);
            }
        }
        if ((cur << 1) <= 100000)
        {
            if (map[cur << 1] > map[cur] + 1)
            {
                map[cur << 1] = map[cur] + 1;
                bfs.push(cur << 1);
            }
        }
    }
    return 0;
}