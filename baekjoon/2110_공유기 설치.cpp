#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, C;
    cin >> N >> C;
    vector<int> house(N);
    for (int i = 0; i < N; ++i)
        cin >> house[i];
    sort(house.begin(), house.end());
    int left = 0, mid, right = house[N - 1], ret;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        int pos = house[0] + mid;
        int cnt = 1;
        for (int i = 1; i < N; ++i)
        {
            if (house[i] < pos)
                continue;
            pos = house[i] + mid;
            ++cnt;
        }
        if (cnt >= C)
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