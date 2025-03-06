#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using pii = pair<int, int>;
using piii = pair<int, pii>;

int N, cost;
int map[201][201];
int parents[201];
vector<piii> roadInfos;
vector<pii> usedRoads;

int find(int x)
{
    if (x == parents[x])
    {
        return x;
    }

    return parents[x] = find(parents[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
    {
        return;
    }

    if (x > y)
    {
        swap(x, y);
    }

    parents[y] = x;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    int maxSize = N * (N + 1) / 2;
    usedRoads.reserve(maxSize);
    roadInfos.reserve(maxSize);

    for (int i = 1; i <= N; ++i)
    {
        parents[i] = i;

        for (int j = 1; j <= N; ++j)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            if (map[i][j] < 0)
            {
                merge(i, j);

                cost += -map[i][j];
            }
            else
            {
                roadInfos.push_back({map[i][j], {i, j}});
            }
        }
    }

    sort(roadInfos.begin(), roadInfos.end());

    for (piii roadInfo : roadInfos)
    {
        pii road = roadInfo.second;

        if (find(road.first) == find(road.second))
        {
            continue;
        }

        merge(road.first, road.second);

        cost += roadInfo.first;

        usedRoads.push_back(road);
    }

    cout << cost << " " << usedRoads.size() << "\n";

    for (pii usedRoad : usedRoads)
    {
        cout << usedRoad.first << " " << usedRoad.second << "\n";
    }
    return 0;
}