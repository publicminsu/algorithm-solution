#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N, k, s, m, e, sum, ret;
int main()
{
    cin >> N >> k;
    s = 1;
    e = N * N;
    while (s <= e)
    {
        m = (s + e) >> 1;
        sum = 0;
        for (int i = 1; i <= N; ++i)
            sum += min((m / i), N);
        if (sum >= k)
        {
            ret = m;
            e = m - 1;
        }
        else
            s = m + 1;
    }
    cout << ret;
    return 0;
}