#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;
int r1, r2, c1, c2, maxN, minGap, len = 2, cnt = 1, y, x;
vector<vector<int>> map;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> r1 >> c1 >> r2 >> c2;
    int start = max(max(abs(r1), abs(r2)), max(abs(c1), abs(c2)));
    r1 += start, c1 += start, r2 += start, c2 += start;
    int gapR = r2 - r1 + 1, gapC = c2 - c1 + 1;
    map = vector<vector<int>>(gapR, vector<int>(gapC));

    y = start - r1, x = start - c1;
    if (y < gapR && x < gapC && y >= 0 && x >= 0)
        map[y][x] = cnt;
    ++cnt;

    for (int i = start - 1; i >= 0; --i, len += 2)
    {
        for (int j = len - 1; j >= 0; --j, ++cnt)
        {
            y = i + j - r1, x = i + len - c1;
            if (y < gapR && x < gapC && y >= 0 && x >= 0)
                map[y][x] = cnt;
        }
        for (int j = len - 1; j >= 0; --j, ++cnt)
        {
            y = i - r1, x = i + j - c1;
            if (y < gapR && x < gapC && y >= 0 && x >= 0)
                map[y][x] = cnt;
        }
        for (int j = 1; j <= len; ++j, ++cnt)
        {
            y = i + j - r1, x = i - c1;
            if (y < gapR && x < gapC && y >= 0 && x >= 0)
                map[y][x] = cnt;
        }
        for (int j = 1; j <= len; ++j, ++cnt)
        {
            y = i + len - r1, x = i + j - c1;
            if (y < gapR && x < gapC && y >= 0 && x >= 0)
                map[y][x] = cnt;
        }
    }

    int maxNum = max(max(map[0][0], map[0][gapC - 1]), max(map[gapR - 1][0], map[gapR - 1][gapC - 1]));
    int numLen = 0;
    while (maxNum)
    {
        maxNum /= 10;
        ++numLen;
    }

    for (int i = 0; i < gapR; ++i)
    {
        for (int j = 0; j < gapC; ++j)
        {
            cout.width(numLen);
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}