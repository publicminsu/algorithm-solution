#include <iostream>
#include <queue>
#include <cmath>
#define MAX 1000001
using namespace std;
int N, M, ret = MAX;
int visted[MAX];
bool isBroken[10];
queue<int> q;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0, j; i < M; ++i)
    {
        cin >> j;
        isBroken[j] = true;
    }
    ret = min(ret, abs(N - 100));
    for (int next = 0; next < 10; ++next)
    {
        if (isBroken[next])
            continue;
        visted[next] = 1;
        q.push(next);
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ret = min(ret, abs(N - cur) + visted[cur]);
        int nextVal = cur * 10;
        for (int i = 0; i < 10; ++i)
        {
            int next = nextVal + i;
            if (isBroken[i] || next == 0 || next >= MAX || visted[next])
                continue;
            visted[next] = visted[cur] + 1;
            q.push(next);
        }
    }
    cout << ret;
    return 0;
}