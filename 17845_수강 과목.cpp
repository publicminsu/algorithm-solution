#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
int N, K, impo, time;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    dp = vector<int>(N + 1);
    while (K--)
    {
        cin >> impo >> time;
        for (int i = N; i >= time; --i)
        {
            int curImpo = dp[i - time] + impo;
            dp[i] = curImpo > dp[i] ? curImpo : dp[i];
        }
    }
    cout << dp[N];
    return 0;
}