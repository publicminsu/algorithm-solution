#include <iostream>
#include <vector>
using namespace std;
#define size N + 1
int N, M;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    dp = vector<int>(size);
    dp[0] = 1;

    for (int i = 0; i < size; ++i)
    {
        if (i + 1 < size)
        {
            dp[i + 1] = (dp[i] + dp[i + 1]) % 1000000007;
        }

        if (i + M < size)
        {
            dp[i + M] = (dp[i] + dp[i + M]) % 1000000007;
        }
    }

    cout << dp[N];
    return 0;
}