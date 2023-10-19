#include <iostream>
#include <vector>
using namespace std;
int N, M, cnt;
vector<vector<char>> graph;
vector<vector<int>> isVisited;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    graph = vector<vector<char>>(N, vector<char>(M));
    isVisited = vector<vector<int>>(N, vector<int>(M));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> graph[i][j];
        }
    }
}
void dfs(int y, int x, int groupNumber)
{
    if (isVisited[y][x]) // 이미 방문했다면
    {
        if (isVisited[y][x] != groupNumber) // 나의 그룹이 아니라면 (새로운 반복이 아님)
        {
            --cnt;
        }
        return;
    }

    isVisited[y][x] = groupNumber;

    if (graph[y][x] == 'D')
    {
        dfs(y + 1, x, groupNumber);
    }
    else if (graph[y][x] == 'U')
    {
        dfs(y - 1, x, groupNumber);
    }
    else if (graph[y][x] == 'L')
    {
        dfs(y, x - 1, groupNumber);
    }
    else // R
    {
        dfs(y, x + 1, groupNumber);
    }
}
void solve()
{
    int groupNumber = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (isVisited[i][j] == 0)
            {
                dfs(i, j, ++groupNumber);
                ++cnt;
            }
        }
    }

    cout << cnt;
}
int main()
{
    input();
    solve();
    return 0;
}