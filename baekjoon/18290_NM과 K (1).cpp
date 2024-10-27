#include <iostream>
using namespace std;
int N, M, K, answer = -987654321, NM;
int map[10][10];
bool isVisited[10][10];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M >> K;

    NM = N * M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
        }
    }
}

void dfs(int cur, int sum, int depth)
{
    if (depth == K)
    {
        answer = max(sum, answer);
        return;
    }

    for (int next = cur; next < NM; ++next)
    {
        int i = next / M;
        int j = next % M;

        if (isVisited[i][j] || (i - 1 >= 0 && isVisited[i - 1][j]) || (j - 1 >= 0 && isVisited[i][j - 1]) || (i + 1 < N && isVisited[i + 1][j]) || (j + 1 < N && isVisited[i][j + 1]))
        {
            continue;
        }

        isVisited[i][j] = true;
        dfs(next, sum + map[i][j], depth + 1);
        isVisited[i][j] = false;
    }
}

void solve()
{
    dfs(0, 0, 0);

    cout << answer;
}

int main()
{
    input();
    solve();
    return 0;
}