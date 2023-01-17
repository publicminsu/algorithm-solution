#include <iostream>
using namespace std;
long long dp[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, min = 3;
    cin >> T;
    dp[0] = dp[1] = dp[2] = 1;
    while (T--)
    {
        int N;
        cin >> N;
        for (int i = min; i < N; ++i)
        {
            dp[i] = dp[i - 2] + dp[i - 3];
        }
        if (min < N)
            min = N;
        cout << dp[N - 1] << "\n";
    }
    return 0;
}