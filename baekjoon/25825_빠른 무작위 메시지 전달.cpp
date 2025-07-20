#include <iostream>
using namespace std;

int costs[12][12];
bool isVisited[6];

int minTime = 987654321;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            cin >> costs[i][j];
        }
    }
}

void dfs(int curStudent, int time, int depth)
{
    if (time >= minTime)
    {
        return;
    }

    if (depth == 6)
    {
        minTime = min(minTime, time);
        return;
    }

    for (int i = 0; i < 6; ++i)
    {
        if (isVisited[i])
        {
            continue;
        }

        int nextStudent = i * 2;
        int nextDepth = depth + 1;

        int nextTime = time + costs[nextStudent][nextStudent + 1];

        isVisited[i] = true;
        dfs(nextStudent + 1, nextTime + costs[curStudent][nextStudent], nextDepth);
        dfs(nextStudent, nextTime + costs[curStudent][nextStudent + 1], nextDepth);
        isVisited[i] = false;
    }
}

int main()
{
    input();

    for (int i = 0; i < 6; ++i)
    {
        int nextStudent = i * 2;

        isVisited[i] = true;
        dfs(nextStudent, costs[nextStudent][nextStudent + 1], 1);
        dfs(nextStudent + 1, costs[nextStudent][nextStudent + 1], 1);
        isVisited[i] = false;
    }

    cout << minTime;
    return 0;
}