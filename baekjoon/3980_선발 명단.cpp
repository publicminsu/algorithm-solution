#include <iostream>
using namespace std;

#define LIMIT 11

int C;
int s[LIMIT][LIMIT];

bool isVisited[LIMIT];

int dfs(int idx, int value)
{
    if (idx == LIMIT)
    {
        return value;
    }

    int ret = 0;

    for (int i = 0; i < LIMIT; ++i)
    {
        if (isVisited[i] || !s[idx][i])
        {
            continue;
        }

        isVisited[i] = true;
        ret = max(ret, dfs(idx + 1, value + s[idx][i]));
        isVisited[i] = false;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> C;

    while (C--)
    {
        for (auto &line : s)
        {
            for (int &i : line)
            {
                cin >> i;
            }
        }

        cout << dfs(0, 0) << "\n";
    }
    return 0;
}