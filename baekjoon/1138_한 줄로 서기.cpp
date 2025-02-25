#include <iostream>
using namespace std;

int N;
int heights[10];
int answer[10];
bool isVisited[10];

void dfs(int index)
{
    if (index == N)
    {
        for (int i = 0; i < N; ++i)
        {
            int cnt = 0;

            for (int j = 0; j < i; ++j)
            {
                if (answer[i] < answer[j])
                {
                    ++cnt;
                }
            }

            if (cnt != heights[answer[i]])
            {
                return;
            }
        }

        for (int i = 0; i < N; ++i)
        {
            cout << answer[i] + 1 << " ";
        }
        exit(0);
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (isVisited[i])
        {
            continue;
        }

        isVisited[i] = true;
        answer[index] = i;
        dfs(index + 1);
        isVisited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> heights[i];
    }

    dfs(0);
    return 0;
}