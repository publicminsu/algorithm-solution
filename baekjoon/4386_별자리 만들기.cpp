#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using pff = pair<float, float>;
using pii = pair<int, int>;
using pfii = pair<float, pii>;

int n;
pff coords[100];
int groups[100];
vector<pfii> dists;
float answer;

int find(int x)
{
    int &group = groups[x];

    if (group == x)
    {
        return group;
    }

    return group = find(group);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x < y)
    {
        groups[x] = y;
    }
    else
    {
        groups[y] = x;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> coords[i].first >> coords[i].second;

        groups[i] = i;
    }

    dists.reserve(n * n);

    for (int i = 0; i < n - 1; ++i)
    {
        const pff &coord1 = coords[i];

        for (int j = i + 1; j < n; ++j)
        {
            const pff &coord2 = coords[j];

            float xx = (coord1.first - coord2.first) * (coord1.first - coord2.first);
            float yy = (coord1.second - coord2.second) * (coord1.second - coord2.second);
            float dist = sqrt(xx + yy);

            dists.push_back({dist, {i, j}});
        }
    }

    sort(dists.begin(), dists.end());

    for (const pfii &p : dists)
    {
        int i = p.second.first;
        int j = p.second.second;

        if (find(i) == find(j))
        {
            continue;
        }

        merge(i, j);
        answer += p.first;
    }

    cout << fixed;
    cout.precision(3);

    cout << answer;
    return 0;
}