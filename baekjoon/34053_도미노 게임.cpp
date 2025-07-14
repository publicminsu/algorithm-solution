#include <iostream>

using namespace std;
using ll = long long;

int N, M, minA = 1e9;
ll sum;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int a;
            cin >> a;
            sum += a;
            minA = min(minA, a);
        }
    }

    cout << sum - minA;
    return 0;
}