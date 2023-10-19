#include <iostream>
using namespace std;
long long dp[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[1] = 1; // 1
    dp[2] = 2; // 1+1 2
    dp[3] = 2; // 1+1+1 3
    dp[4] = 3; // 1*4 2+2 1+2+1;
    dp[5] = 3; // 1*5 2+1+2 1+3+1;
    dp[6] = 6; // 1*6 1+2+2+1 1+1+2+1+1 2+1+1+2 2+2+2 3+3
    int T, min = 7;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = min; i <= n; ++i)
        {
            dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6]) % 1000000009; // 양쪽에 1, 2, 3을 붙인다.
        }
        cout << dp[n] << "\n";
        if (n > min)
            min = n;
    }
    return 0;
}