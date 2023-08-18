#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
int N, M, dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1}, ret = 0, idx = 0;
vector<vector<int>> map, group;
vector<int> groupSum;
unordered_set<int> us;
void bfs(int y, int x)
{
    int sum = 1;
    group[y][x] = idx;
    queue<pii> q;
    q.push({y, x});
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            pii next = {cur.first + dy[i], cur.second + dx[i]};
            if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= M ||
                !map[next.first][next.second] || group[next.first][next.second] != -1)
                continue;
            group[next.first][next.second] = idx;
            ++sum;
            q.push(next);
        }
    }
    groupSum.push_back(sum);
    ++idx;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    map = group = vector<vector<int>>(N, vector<int>(M, -1));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j])
            {
                if (group[i][j] == -1)
                    bfs(i, j);
            }
            else
            {
                int sum = 1;
                us.clear();
                for (int k = 0; k < 4; ++k)
                {
                    int ny = i + dy[k], nx = j + dx[k];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= M || !map[ny][nx] || us.find(group[ny][nx]) != us.end())
                        continue;
                    if (group[ny][nx] == -1)
                        bfs(ny, nx);
                    us.insert(group[ny][nx]);
                    sum += groupSum[group[ny][nx]];
                }
                ret = max(ret, sum);
            }
        }
    cout << ret;
    return 0;
}