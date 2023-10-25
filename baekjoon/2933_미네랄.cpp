#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct pos
{
    int y, x;
    const pos operator+(const pos &other) const
    {
        return {this->y + other.y, this->x + other.x};
    }
} dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<char>> map;
vector<vector<bool>> isVisited;
int R, C;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> R >> C;
    map = vector<vector<char>>(R, vector<char>(C));
    isVisited = vector<vector<bool>>(R, vector<bool>(C));

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> map[i][j];
        }
    }
}
void bfs() // 바닥과 이어진 부분 찾기
{
    fill(isVisited.begin(), isVisited.end(), vector<bool>(C));
    queue<pos> q;
    for (int i = 0; i < C; ++i) // 바닥과 이어진 부분 확인
    {
        if (map[R - 1][i] == '.')
        {
            continue;
        }

        isVisited[R - 1][i] = true;
        q.push({R - 1, i});
    }
    while (!q.empty()) // 바닥과 이어진 부분 탐색
    {
        pos cur = q.front();
        q.pop();

        for (pos d : dir)
        {
            pos next = cur + d;

            if (next.y < 0 || next.x < 0 || next.y >= R || next.x >= C || map[next.y][next.x] == '.' || isVisited[next.y][next.x])
            {
                continue;
            }

            isVisited[next.y][next.x] = true;
            q.push(next);
        }
    }
}
void drop() // 공중에 뜬 클러스터 확인 및 이동
{
    int len = R;
    vector<pos> clusters;
    for (int i = 0; i < R - 1; ++i) // 클러스터 수집
    {
        for (int j = 0; j < C; ++j)
        {
            if (isVisited[i][j] || map[i][j] == '.') // 바닥과 연결됐거나 빈칸인 경우
            {
                continue;
            }
            clusters.push_back({i, j});
        }
    }
    if (clusters.empty()) // 클러스터가 없다면
    {
        return;
    }
    for (pos cur : clusters)
    {
        for (int i = cur.y + 1, h = 1; i < R; ++i, ++h)
        {
            if (isVisited[i][cur.x]) // 바닥과 연결된 부위에 도달한 경우
            {
                len = min(len, h - 1);
                break;
            }
            else if (map[i][cur.x] == 'x') // 클러스터에 도달한 경우
            {
                break;
            }
            else if (i == R - 1) // 끝에 도달한 경우
            {
                len = min(len, h);
            }
        }
    }

    for (pos cur : clusters)
    {
        map[cur.y][cur.x] = '.';
    }
    for (pos cur : clusters)
    {
        map[cur.y + len][cur.x] = 'x';
    }
}
bool isRemove(int height, int i) // 미네랄이면 삭제
{
    if (map[height][i] == 'x')
    {
        map[height][i] = '.';
        bfs();
        drop();
        return true;
    }
    return false;
}
void find(int height, bool isRight) // 막대와 부딪치는 미네랄 찾기
{
    if (isRight)
    {
        for (int i = C - 1; i >= 0; --i)
        {
            if (isRemove(height, i))
            {
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < C; ++i)
        {
            if (isRemove(height, i))
            {
                break;
            }
        }
    }
}
void solve()
{
    int N, height;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> height;
        find(R - height, i & 1);
    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cout << map[i][j];
        }
        cout << "\n";
    }
}
int main()
{
    input();
    solve();
    return 0;
}