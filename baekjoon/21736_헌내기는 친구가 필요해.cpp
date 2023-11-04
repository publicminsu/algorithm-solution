#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<char>> map;
vector<vector<bool>> isVisited;
int N, M;
struct pos
{
    int y, x;
    const pos operator+(const pos &other) const
    {
        return {y + other.y, x + other.x};
    }
    bool isOut()
    {
        return y < 0 || x < 0 || y >= N || x >= M || isVisited[y][x] || map[y][x] == 'X';
    }
} dir[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pos> q;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    isVisited = vector<vector<bool>>(N, vector<bool>(M));
    map = vector<vector<char>>(N, vector<char>(M));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];

            if (map[i][j] == 'I') // 도연이의 좌표를 저장
            {
                q.push({i, j});
                isVisited[i][j] = true;
            }
        }
    }
}
void bfs()
{
    int cnt = 0;
    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();
        for (pos d : dir)
        {
            pos next = d + cur;

            if (next.isOut()) // 범위를 벗어나는가?
            {
                continue;
            }

            isVisited[next.y][next.x] = true;

            if (map[next.y][next.x] == 'P') // 만약 사람이라면
            {
                ++cnt;
            }

            q.push(next);
        }
    }

    if (cnt) // 만날 수 있는 사람의 수가 존재하는지?
    {
        cout << cnt;
    }
    else
    {
        cout << "TT";
    }
}
int main()
{
    input();
    bfs();
    return 0;
}