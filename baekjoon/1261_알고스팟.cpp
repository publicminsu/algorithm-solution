#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, int> pii;
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M;
    string row;
    cin >> M >> N;
    vector<vector<bool>> map(N, vector<bool>(M));
    vector<vector<int>> dp(N, vector<int>(M, -1));
    queue<pii> q;
    for (int i = 0, k; i < N; ++i)
    {
        cin >> row;
        for (int j = 0; j < M; ++j)
        {
            map[i][j] = row[j] - '0';
        }
    }
    q.push({0, 0});
    dp[0][0] = 0;
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            pii next = {cur.first + dy[i], cur.second + dx[i]};
            if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= M)
                continue;
            int nextDPvalue = dp[cur.first][cur.second];
            if (map[next.first][next.second])
                ++nextDPvalue;
            if (dp[next.first][next.second] != -1 && nextDPvalue >= dp[next.first][next.second])
                continue;
            dp[next.first][next.second] = nextDPvalue;
            q.push(next);
        }
    }
    cout << dp[N - 1][M - 1];
    return 0;
}