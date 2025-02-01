#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> sensors, dist;
int N, K, sum;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;

    dist.reserve(N - 1);
    sensors = vector<int>(N);

    for (int &sensor : sensors)
    {
        cin >> sensor;
    }

    sort(sensors.begin(), sensors.end());

    for (int i = 0; i < N - 1; ++i)
    {
        dist.push_back(sensors[i + 1] - sensors[i]);
    }

    sort(dist.begin(), dist.end());

    for (int i = 0; i < (int)dist.size() - K + 1; ++i)
    {
        sum += dist[i];
    }

    cout << sum;
    return 0;
}