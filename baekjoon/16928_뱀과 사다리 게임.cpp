#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int visted[101];
int jump[101];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M;
    cin >> N >> M;
    queue<int> q;
    for (int i = 0; i < N + M; ++i)
    {
        int a, b;
        cin >> a >> b;
        jump[a] = b;
    }
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        if (cur == 100)
            break;
        q.pop();
        for (int i = 1; i <= 6; ++i)
        {
            int next = cur + i;
            if (next > 100)
                continue;
            if (jump[next])
            {
                next = jump[next];
            }
            if (visted[next])
                continue;
            visted[next] = visted[cur] + 1;
            q.push(next);
        }
    }
    cout << visted[100];
    return 0;
}
