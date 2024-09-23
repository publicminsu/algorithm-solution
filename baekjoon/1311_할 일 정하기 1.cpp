#include <iostream>
#include <vector>
using namespace std;
#define INF 200001
int N;
vector<vector<int>> graph;
vector<int> dp;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    dp = vector<int>(1 << N, INF);
    graph = vector<vector<int>>(N, vector<int>(N));
    for (vector<int> &line : graph)
    {
        for (int &i : line)
        {
            cin >> i;
        }
    }
}

int count(int flag)
{
    int cnt = 0;
    while (flag)
    {
        cnt += (flag & 1);
        flag >>= 1;
    }
    return cnt;
}

void solve()
{
    dp[0] = 0;

    for (int flag = 0; flag < 1 << N; flag++)
    {
        int people = count(flag);

        for (int job = 0; job < N; job++)
        {
            if (flag & (1 << job))
            {
                continue;
            }

            int nextFlag = flag | (1 << job);

            dp[nextFlag] = min(dp[nextFlag], dp[flag] + graph[people][job]);
        }
    }

    cout << dp[(1 << N) - 1];
}

int main()
{
    input();
    solve();
    return 0;
}
