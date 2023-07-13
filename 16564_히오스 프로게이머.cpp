#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll N, K, left = 1, right = 2000000000, ret;
    cin >> N >> K;
    vector<int> level(N);
    for (int i = 0; i < N; ++i)
        cin >> level[i];
    while (left <= right)
    {
        ll mid = (left + right) >> 1, k = 0;
        for (int i : level)
            if (mid > i)
                k += mid - i;
        if (K >= k)
        {
            left = mid + 1;
            ret = mid;
        }
        else
            right = mid - 1;
    }
    cout << ret;
    return 0;
}