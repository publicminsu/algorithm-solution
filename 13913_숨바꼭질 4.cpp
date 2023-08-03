#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MaxN 100001
int isVisited[MaxN];
int parent[MaxN];
void recur(int cur)
{
    if (parent[cur] != -1)
        recur(parent[cur]);
    cout << cur << " ";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    memset(parent, -1, sizeof(parent));
    int N, K;
    cin >> N >> K;
    queue<int> q;
    isVisited[N] = 1;
    q.push(N);
    while (!q.empty())
    {
        int cur = q.front(), next;
        q.pop();
        next = cur + 1;
        if (next < MaxN && !isVisited[next])
        {
            isVisited[next] = isVisited[cur] + 1;
            parent[next] = cur;
            if (next == K)
                break;
            q.push(next);
        }
        next = cur - 1;
        if (next >= 0 && !isVisited[next])
        {
            isVisited[next] = isVisited[cur] + 1;
            parent[next] = cur;
            if (next == K)
                break;
            q.push(next);
        }
        next = cur << 1;
        if (next < MaxN && !isVisited[next])
        {
            isVisited[next] = isVisited[cur] + 1;
            parent[next] = cur;
            if (next == K)
                break;
            q.push(next);
        }
    }
    cout << isVisited[K] - 1 << "\n";
    recur(K);
    return 0;
}