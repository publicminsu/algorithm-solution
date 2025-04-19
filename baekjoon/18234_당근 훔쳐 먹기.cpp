#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int N, T;
ll sum;
ll p[200000];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> T;

    for (int i = 0, w; i < N; ++i)
    {
        cin >> w >> p[i];
        sum += w;
    }

    sort(p, p + N);

    for (int i = 0; i < N; ++i)
    {
        sum += p[i] * (T - N + i);
    }

    cout << sum;
    return 0;
}