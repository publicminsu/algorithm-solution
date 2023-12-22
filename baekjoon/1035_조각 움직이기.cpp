#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define BOARD_SIZE 5
struct pos
{
    int y, x;
    const pos operator+(const pos &other) const
    {
        return {y + other.y, x + other.x};
    }
    const bool isOut() const
    {
        return y < 0 || x < 0 || y >= BOARD_SIZE || x >= BOARD_SIZE;
    }
} pieces[BOARD_SIZE], dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char board[BOARD_SIZE][BOARD_SIZE];
bool isVisited[BOARD_SIZE][BOARD_SIZE];
int pieceLen, answer = 987654321;
bool bfs()
{
    memset(isVisited, false, sizeof(isVisited));
    int cnt = 1;
    queue<pos> q;

    pos first = pieces[0];
    isVisited[first.y][first.x] = true;
    q.push(first);

    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();
        for (const pos &d : dir)
        {
            pos next = d + cur;
            if (next.isOut() || board[next.y][next.x] == '.' || isVisited[next.y][next.x]) // 범위 확인, 조각인지 확인
            {
                continue;
            }
            isVisited[next.y][next.x] = true;
            ++cnt;
            q.push(next);
        }
    }
    return cnt == pieceLen;
}
void dfs(int idx, int sum)
{
    if (sum >= answer) // 저장된 이동 횟수보다 더 필요하다면
    {
        return;
    }
    else
    {
        if (bfs()) // 조각이 붙어있는지 확인
        {
            answer = min(sum, answer);
            return;
        }
    }
    if (idx == pieceLen) // 모든 조각 확인했다면
    {
        return;
    }

    dfs(idx + 1, sum); // 안 움직이기
    pos origin = pieces[idx];
    board[origin.y][origin.x] = '.';

    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        for (int x = 0; x < BOARD_SIZE; ++x)
        {
            if (board[y][x] == '*') // 만약 이미 조각이 있다면
            {
                continue;
            }
            board[y][x] = '*';
            pieces[idx] = {y, x};
            dfs(idx + 1, sum + abs(origin.y - y) + abs(origin.x - x)); // 조각의 거리만큼 값 더하기
            board[y][x] = '.';
        }
    }
    pieces[idx] = origin;
    board[origin.y][origin.x] = '*';
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        for (int x = 0; x < BOARD_SIZE; ++x)
        {
            cin >> board[y][x];
            if (board[y][x] == '*') // 조각이라면
            {
                pieces[pieceLen++] = {y, x};
            }
        }
    }
}
int main()
{
    input();
    dfs(0, 0);
    cout << answer;
    return 0;
}