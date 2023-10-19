#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int a[101], tc, N, M, idx;
queue<pii> q;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> tc;
    while (tc--)
    {
        while (!q.empty())
            q.pop();
        idx = 0;
        cin >> N >> M;
        for (int i = 0; i < N; ++i)
        {
            cin >> a[i];
            q.push({a[i], i});
        }
        sort(a, a + N, greater<int>());
        while (true)
        {
            pii cur = q.front();
            q.pop();
            if (cur.first == a[idx])
            {
                ++idx;
                if (cur.second == M)
                {
                    cout << idx << "\n";
                    break;
                }
            }
            else
                q.push(cur);
        }
    }
    return 0;
}