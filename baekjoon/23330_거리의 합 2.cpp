#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int n;
ll x[500001];
ll prefixSum[500001];
ll answer;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }

    sort(x, x + n);

    prefixSum[0] = x[0];

    for (int i = 0; i < n - 1; ++i)
    {
        prefixSum[i + 1] = prefixSum[i] + x[i + 1];
    }

    for (int i = 1; i < n; ++i)
    {
        answer += (x[i] * i) - prefixSum[i - 1];
    }

    cout << answer * 2;
    return 0;
}