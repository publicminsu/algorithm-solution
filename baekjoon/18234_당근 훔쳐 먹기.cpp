#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;
int N, T;
ll sum;
pli carrotInfos[200000];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> T;

    for (int i = 0; i < N; ++i)
    {
        pli &carrotInfo = carrotInfos[i];
        cin >> carrotInfo.second >> carrotInfo.first;
    }

    sort(carrotInfos, carrotInfos + N, greater<>());

    for (int i = 0; i < N; ++i)
    {
        const pli &carrotInfo = carrotInfos[i];

        sum += carrotInfo.second;
        sum += carrotInfo.first * (T - i - 1);
    }

    cout << sum;
    return 0;
}