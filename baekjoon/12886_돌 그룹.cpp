#include <iostream>
#include <algorithm>
using namespace std;
bool isVisited[1001][1001];
int abc[3];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0; i < 3; ++i)
    {
        cin >> abc[i];
    }
}

bool isPossible(int buffer[3])
{
    if (buffer[0] == buffer[1] && buffer[0] == buffer[2])
    {
        return true;
    }

    sort(buffer, buffer + 3);

    if (isVisited[buffer[0]][buffer[1]])
    {
        return false;
    }

    isVisited[buffer[0]][buffer[1]] = true;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = i + 1; j < 3; ++j)
        {
            int k = 3 - (i + j);
            int nextBuffer[3] = {buffer[i] * 2, buffer[j] - buffer[i], buffer[k]};

            if (isPossible(nextBuffer))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    input();
    cout << isPossible(abc);
    return 0;
}