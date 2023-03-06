#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> dp(N + 1), nums(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> nums[i];
    dp[1] = nums[1];
    if (N > 1)
    {
        dp[2] = nums[1] + nums[2];
        for (int i = 3; i <= N; ++i)
        {
            dp[i] = max(dp[i - 2], dp[i - 3] + nums[i - 1]) + nums[i];
        }
    }
    cout << dp[N];
    return 0;
}