#include <iostream>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int H, N;
pii lights[200000];
int dists[200000];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> H >> N;
    for (int i = 0; i < N; ++i)
    {
        int c;
        cin >> c >> c;
        lights[i] = {c, i};
    }

    sort(lights, lights + N, greater<>());
    for (int i = 0; i < N; ++i)
    {
        const pii &light = lights[i];
        dists[light.second] = N - i;
    }

    cout << "YES\n";

    for (int i = 0; i < N; ++i)
    {
        const int &dist = dists[i];
        cout << dist << " ";
    }
    return 0;
}