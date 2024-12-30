#include <iostream>
using namespace std;
int h, w, c, idx = 1;
int map[10][10];
int cnts[10];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> h >> w >> c;
    for (int i = 1; i <= c; ++i)
    {
        cin >> cnts[i];
    }

    for (int i = 0; i < w; ++i)
    {
        for (int j = 0; j < h; ++j)
        {
            if (cnts[idx])
            {
                --cnts[idx];
            }
            else
            {
                ++idx;
                --cnts[idx];
            }

            map[j][i] = idx;
        }
    }

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cout << map[i][j];
        }
        cout << "\n";
    }

    return 0;
}