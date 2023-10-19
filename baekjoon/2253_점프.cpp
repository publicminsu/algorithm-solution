#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dp(N + 1, vector<int>(150, 10001));
    vector<bool> small(N + 1);
    while (M--)
    {
        int i;
        cin >> i;
        small[i] = true;
    }
    if (small[2])
    {
        cout << -1;
        return 0;
    }
    queue<pii> q;
    dp[2][1] = 1;
    q.push({2, 1});
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        int curIdx = cur.first, curVal = cur.second;
        if (cur.first == N)
        {
            cout << dp[curIdx][curVal];
            return 0;
        }
        for (int i = -1; i <= 1; ++i)
        {
            int nextVal = curVal + i, nextIdx = curIdx + nextVal;
            if (nextIdx > N || small[nextIdx] || dp[nextIdx][nextVal] <= dp[curIdx][curVal] + 1 || curVal == 0)
                continue;
            dp[nextIdx][nextVal] = dp[curIdx][curVal] + 1;
            q.push({nextIdx, nextVal});
        }
    }
    cout << -1;
    return 0;
}