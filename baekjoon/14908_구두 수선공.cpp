#include <iostream>
#include <algorithm>
using namespace std;

using pdi = pair<double, int>;

int N;
pdi percents[1000];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        int T, S;
        cin >> T >> S;

        percents[i - 1] = {(double)S / T, -i};
    }

    sort(percents, percents + N, greater<>());

    for (int i = 0; i < N; ++i)
    {
        cout << -percents[i].second << " ";
    }
    return 0;
}