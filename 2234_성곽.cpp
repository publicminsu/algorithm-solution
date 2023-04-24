#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> map, visted;
vector<int> area;
unordered_set<int> nearRoom[2501];
int N, M, cnt = 0, dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
void init()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    map = visted = vector<vector<int>>(M, vector<int>(N, -1));
    for (int i = M - 1; i >= 0; --i)
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
        }
    return;
}
void bfs(int y, int x)
{
    queue<pii> q;
    q.push({y, x});
    visted[y][x] = cnt;
    int size = 1;
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            pii next = {cur.first + dy[i], cur.second + dx[i]};
            if (next.first < 0 || next.second < 0 || next.first >= M || next.second >= N) // 범위에 벗어난 경우
                continue;
            int nextRoom = visted[next.first][next.second];
            if ((1 << i) & map[cur.first][cur.second]) // 막힌 벽
            {
                if (nextRoom != -1 && nextRoom != cnt) // 방문한 적 있고 나랑 다른 방이면
                {
                    // 인접한 방 목록에 추가한다.
                    nearRoom[cnt].insert(nextRoom);
                    nearRoom[nextRoom].insert(cnt);
                }
            }
            else
            {
                if (nextRoom != -1) // 방문했다면 무시한다.
                    continue;
                visted[next.first][next.second] = cnt;
                q.push(next);
                ++size;
            }
        }
    }
    area.push_back(size);
    ++cnt;
    return;
}
int main()
{
    init();
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            if (visted[i][j] == -1)
                bfs(i, j);
    int ret1 = 0, ret2 = 0;
    for (int i = 0; i < cnt; ++i)
    {
        int s1 = area[i];
        ret1 = s1 > ret1 ? s1 : ret1;
        for (int j : nearRoom[i])
        {
            int sum = s1 + area[j];
            ret2 = sum > ret2 ? sum : ret2;
        }
    }
    cout << cnt << "\n"
         << ret1 << "\n"
         << ret2;
    return 0;
}