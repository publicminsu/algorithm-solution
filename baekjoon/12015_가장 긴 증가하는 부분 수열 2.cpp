#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    vector<int> dp;
    cin >> N;
    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        auto it = lower_bound(dp.begin(), dp.end(), j);
        if (it == dp.end())
            dp.push_back(j);
        else
            dp[it - dp.begin()] = j;
    }
    cout << dp.size();
    return 0;
}