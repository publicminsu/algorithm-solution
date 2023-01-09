#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, ret = 0;
    cin >> N;
    vector<int> moneys(N);
    ll low = 0, mid, high = 0;
    for (int i = 0; i < N; ++i)
    {
        int money;
        cin >> money;
        moneys.push_back(money);
        if (high < money)
            high = money;
    }
    cin >> M;
    while (low <= high)
    {
        mid = (low + high) / 2;
        ll sum = 0;
        for (int money : moneys)
            sum += ((money <= mid) ? money : mid);
        if (sum <= M)
        {
            low = mid + 1;
            if (ret < mid)
                ret = mid;
        }
        else
            high = mid - 1;
    }
    cout << ret;
    return 0;
}