#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using pii = pair<int, int>;
using piii = pair<int, pii>;

int H, W, cnt;
int lightMap[1000][1000];
bool isVisited[1000][1000];
vector<piii> v;
queue<pii> q;
pii dir[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> H >> W;

    v.reserve(H * W);

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            int &light = lightMap[i][j];

            cin >> light;

            if (light > 0)
            {
                v.push_back({light, {i, j}});
            }
        }
    }
}

bool bfs()
{
    auto add = [](const pii &p1, const pii &p2)
    {
        pii ret = {p1.first + p2.first, p1.second + p2.second};
        return ret;
    };

    for (const piii &p : v)
    {
        const pii &pSecond = p.second;
        const int &pY = pSecond.first;
        const int &pX = pSecond.second;

        if (isVisited[pY][pX])
        {
            continue;
        }

        ++cnt;

        if (p.first == 1)
        {
            continue;
        }

        q.push(p.second);

        while (!q.empty())
        {
            pii cur = q.front();
            q.pop();

            const int &curY = cur.first;
            const int &curX = cur.second;
            const int &curValue = lightMap[curY][curX];

            if (curValue <= 1)
            {
                continue;
            }

            for (const pii &d : dir)
            {
                pii next = add(cur, d);

                const int &nextY = next.first;
                const int &nextX = next.second;

                if (nextY >= H || nextX >= W || nextY < 0 || nextX < 0)
                {
                    continue;
                }

                int &nextValue = lightMap[nextY][nextX];

                if (nextValue == -1)
                {
                    continue;
                }

                int diff = curValue - nextValue;

                if (diff == 1)
                {
                    if (!isVisited[nextY][nextX])
                    {
                        q.push(next);
                        isVisited[nextY][nextX] = true;
                    }
                }
                else if (diff > 1)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void solve()
{
    sort(v.begin(), v.end(), greater<piii>());

    cout << (bfs() ? cnt : -1);

    return;
}

int main()
{
    input();
    solve();
    return 0;
}