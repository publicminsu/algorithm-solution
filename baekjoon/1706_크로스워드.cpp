#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int R, C;
char map[20][20];
vector<string> v;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> map[i][j];
        }
    }

    string buffer;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (map[i][j] == '#')
            {
                if (buffer.size() > 1)
                {
                    v.push_back(buffer);
                }
                buffer.clear();

                continue;
            }

            buffer += map[i][j];
        }

        if (buffer.size() > 1)
        {
            v.push_back(buffer);
        }
        buffer.clear();
    }

    for (int i = 0; i < C; ++i)
    {
        for (int j = 0; j < R; ++j)
        {
            if (map[j][i] == '#')
            {
                if (buffer.size() > 1)
                {
                    v.push_back(buffer);
                }
                buffer.clear();

                continue;
            }

            buffer += map[j][i];
        }

        if (buffer.size() > 1)
        {
            v.push_back(buffer);
        }
        buffer.clear();
    }

    sort(v.begin(), v.end());

    cout << v.front();
    return 0;
}