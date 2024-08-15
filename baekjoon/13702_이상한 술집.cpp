#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int N, K;
ll l, m, r;
vector<ll> nums;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;

    nums = vector<ll>(N);

    for (ll &num : nums)
    {
        cin >> num;

        r = max(r, num);
    }

    l = 1;

    while (l <= r)
    {
        int cnt = 0;

        m = (l + r) / 2;

        for (const ll &num : nums)
        {
            cnt += num / m;
        }

        if (cnt < K)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << r;
    return 0;
}