#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pip; // 기내식 점수, 횟수, 마을 번호
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, K, ret = 0;
    cin >> N >> M >> K;
    vector<vector<pii>> graph(N + 1, vector<pii>());
    vector<vector<int>> visted(M + 1, vector<int>(N + 1, -1));
    for (int i = 0, a, b, c; i < K; ++i)
    {
        cin >> a >> b >> c;
        if (a > b)
            continue;
        graph[a].push_back({b, c});
    }
    queue<pip> q;
    q.push({0, {1, 1}});
    visted[1][1] = 0;
    while (!q.empty())
    {
        pip cur = q.front();
        q.pop();
        int cnt = cur.second.first;
        if (visted[cnt][cur.second.second] > cur.first || cur.second.first == M)
            continue;
        for (pii next : graph[cur.second.second])
        {
            int nextScore = cur.first + next.second;
            if (visted[cnt + 1][next.first] >= nextScore)
                continue;
            visted[cnt + 1][next.first] = nextScore;
            q.push({nextScore, {cnt + 1, next.first}});
        }
    }
    for (int i = 1; i <= M; ++i)
        ret = visted[i][N] > ret ? visted[i][N] : ret;
    cout << ret;
    return 0;
}