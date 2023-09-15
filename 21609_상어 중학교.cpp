#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1}, maxSize, rainbowMaxSize, r, c;
vector<vector<int>> map, temp;
vector<vector<bool>> isVisited, isBFSVisited;
void drop(int i, int j)
{
    int index = map[i][j];
    map[i][j] = -2;
    for (int k = i + 1; k < N; ++k)
    {
        if (map[k][j] == -2)
            continue;
        else
        {
            map[k - 1][j] = index;
            return;
        }
    }
    map[N - 1][j] = index;
}
void bfs(int y, int x)
{
    if (isVisited[y][x] || map[y][x] == 0 || map[y][x] == -1 || map[y][x] == -2) // 방문 여부, 무지개 여부,검은색 여부, 빈 공간
        return;
    isVisited[y][x] = isBFSVisited[y][x] = true;
    int cnt = 1, rainbowCnt = 0;
    queue<pii> q;
    q.push({y, x});
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            pii next = {cur.first + dy[i], cur.second + dx[i]};
            if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= N) // 범위 확인
                continue;
            if (isBFSVisited[next.first][next.second] || map[next.first][next.second] == -1 || map[next.first][next.second] == -2)
                continue;
            if (map[next.first][next.second] && map[next.first][next.second] != map[y][x])
                continue;
            isBFSVisited[next.first][next.second] = true;
            ++cnt;
            if (map[next.first][next.second])
                isVisited[next.first][next.second] = true;
            else
                ++rainbowCnt;
            q.push(next);
        }
    }
    if (cnt > maxSize || (cnt == maxSize && (rainbowCnt > rainbowMaxSize || (rainbowCnt == rainbowMaxSize && (y > r || (y == r && x > c))))))
    {
        maxSize = cnt;
        rainbowMaxSize = rainbowCnt;
        r = y;
        c = x;
    }
    for (vector<bool> &i : isBFSVisited)
        fill(i.begin(), i.end(), 0);
}
void deleteBfs(int y, int x)
{
    isBFSVisited[y][x] = true;
    int curIdx = map[y][x];
    map[y][x] = -2;
    queue<pii> q;
    q.push({y, x});
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            pii next = {cur.first + dy[i], cur.second + dx[i]};
            if (next.first < 0 || next.second < 0 || next.first >= N || next.second >= N) // 범위 확인
                continue;
            if (isBFSVisited[next.first][next.second] || map[next.first][next.second] == -1 || map[next.first][next.second] == -2)
                continue;
            if (map[next.first][next.second] && map[next.first][next.second] != curIdx)
                continue;
            isBFSVisited[next.first][next.second] = true;
            map[next.first][next.second] = -2;
            q.push(next);
        }
    }
    for (vector<bool> &i : isBFSVisited)
        fill(i.begin(), i.end(), 0);
}
void gravity()
{
    for (int i = N - 2; i >= 0; --i)
        for (int j = 0; j < N; ++j)
        {
            if (map[i][j] < 0)
                continue;
            drop(i, j);
        }
}
void turn()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp[i][j] = map[j][N - 1 - i];
    map = temp;
}
void solve()
{
    int ret = 0;
    while (true)
    {
        maxSize = rainbowMaxSize = r = c = -1;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                bfs(i, j);
        if (maxSize == -1 || maxSize == 1)
            break;
        ret += maxSize * maxSize;
        deleteBfs(r, c);
        gravity();
        turn();
        gravity();
        for (vector<bool> &i : isVisited)
            fill(i.begin(), i.end(), 0);
    }
    cout << ret;
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    map = temp = vector<vector<int>>(N, vector<int>(N));
    isVisited = isBFSVisited = vector<vector<bool>>(N, vector<bool>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];
}
int main()
{
    input();
    solve();
    return 0;
}