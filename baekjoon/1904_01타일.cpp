#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> dp(N);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < N; ++i)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
    }
    cout << dp[N - 1];
    return 0;
}