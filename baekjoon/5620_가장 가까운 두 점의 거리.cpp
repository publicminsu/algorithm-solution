#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

using pos = pair<int, int>;

int n;
pos posArr[500000];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> posArr[i].first >> posArr[i].second;
    }
}

int calcDistSq(const pos &a, const pos &b)
{
    int dx = a.first - b.first;
    int dy = a.second - b.second;

    return dx * dx + dy * dy;
}

pos swapXY(const pos &a)
{
    return {a.second, a.first};
}

int getMinDistSq()
{
    sort(posArr, posArr + n);

    set<pos> s;
    s.insert(swapXY(posArr[0]));
    s.insert(swapXY(posArr[1]));

    int minDistSq = calcDistSq(posArr[0], posArr[1]);
    int startIndex = 0;

    for (int index = 2; index < n; ++index)
    {
        const pos &curPos = posArr[index];

        while (startIndex < index)
        {
            const pos &startPos = posArr[startIndex];
            int dx = startPos.first - curPos.first;

            if (dx * dx < minDistSq)
            {
                break;
            }
            else
            {
                s.erase(swapXY(startPos));
                ++startIndex;
            }
        }

        int minDist = sqrt(minDistSq);

        auto lb = s.lower_bound({curPos.second - minDist, -10000});
        auto ub = s.upper_bound({curPos.second + minDist, 10000});

        while (lb != ub)
        {
            minDistSq = min(minDistSq, calcDistSq(curPos, swapXY(*lb)));
            ++lb;
        }

        s.insert(swapXY(curPos));
    }

    return minDistSq;
}

int main()
{
    input();
    cout << getMinDistSq();
    return 0;
}