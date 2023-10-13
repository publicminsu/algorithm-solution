#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> in;            // 진입 차수
vector<vector<int>> graph; // 가수 순서
int N, M;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;
    in = vector<int>(N + 1);
    graph = vector<vector<int>>(N + 1, vector<int>());

    while (M--)
    {
        int size, start, end;
        cin >> size;
        cin >> start;

        while (--size)
        {
            cin >> end;
            ++in[end];
            graph[start].push_back(end);
            start = end;
        }
    }
}
void solve()
{
    queue<int> q, ret;

    for (int i = 1; i <= N; ++i)
    {
        if (in[i] == 0) // 진입 차수가 0이면
        {
            q.push(i);
            ret.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            if (--in[next] == 0) // 진입 차수가 0이면
            {
                q.push(next);
                ret.push(next);
            }
        }
    }

    if (ret.size() == N)
    {
        while (!ret.empty())
        {
            cout << ret.front() << "\n";
            ret.pop();
        }
    }
    else
    {
        cout << 0;
    }
}
int main()
{
    input();
    solve();
    return 0;
}