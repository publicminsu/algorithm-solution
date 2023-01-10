#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    ll high = 0, low = 0, mid, ret;
    vector<int> times;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int time;
        cin >> time;
        times.push_back(time);
        if (high < time)
            high = time;
    }
    high = M * high;
    while (low <= high)
    {
        ll sum = 0;
        mid = (low + high) >> 1;
        for (int time : times)
            sum += mid / time;
        if (sum >= M)
        {
            high = mid - 1;
            ret = mid;
        }
        else
            low = mid + 1;
    }
    cout << ret;
    return 0;
}