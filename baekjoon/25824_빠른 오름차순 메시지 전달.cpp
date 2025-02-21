#include <iostream>
using namespace std;
int dist[12][12];
int answer = 987654321;

void dfs(int idx, int value)
{
    if (answer <= value)
    {
        return;
    }

    int otherIdx = idx % 2 ? idx - 1 : idx + 1;

    value += dist[idx][otherIdx];

    if (idx >= 10)
    {
        answer = min(answer, value);
        return;
    }

    int nextIdx = ((idx / 2) + 1) * 2;

    for (int i = 0; i < 2; ++i)
    {
        dfs(nextIdx + i, value + dist[otherIdx][nextIdx + i]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            cin >> dist[i][j];
        }
    }

    for (int i = 0; i < 2; ++i)
    {
        dfs(i, 0);
    }

    cout << answer;
    return 0;
}