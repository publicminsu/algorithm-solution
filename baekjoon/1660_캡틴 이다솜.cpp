#include <iostream>
#include <vector>
using namespace std;
#define MAX_NUMS 121
int nums[MAX_NUMS], N;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 1; i < MAX_NUMS; ++i)
    {
        nums[i] = i * (i + 1) * (i + 2) / 6;
    }

    cin >> N;
    dp = vector<int>(N + 1);

    for (int i = 1; i < N + 1; ++i)
    {
        dp[i] = i;
    }

    for (int i = 0; i < MAX_NUMS; ++i)
    {
        for (int j = nums[i]; j <= N; ++j)
        {
            dp[j] = min(dp[j], dp[j - nums[i]] + 1);
        }
    }

    cout << dp[N];
    return 0;
}