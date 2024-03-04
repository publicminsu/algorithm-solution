#include <iostream>
#include <cstring>
using namespace std;
bool isVisited[1001];
int graph[1001];
int T, N, answer;
void dfs(int cur)
{
    if (isVisited[cur]) // 이미 방문한 경우
    {
        return;
    }

    isVisited[cur] = true;
    dfs(graph[cur]);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        memset(isVisited, false, sizeof(isVisited));
        answer = 0;

        cin >> N;

        for (int i = 1; i <= N; ++i)
        {
            cin >> graph[i];
        }

        for (int i = 1; i <= N; ++i)
        {
            if (isVisited[i]) // 이미 방문한 경우
            {
                continue;
            }
            dfs(i);
            ++answer;
        }

        cout << answer << "\n";
    }
    return 0;
}