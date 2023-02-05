#include <iostream>
#include <string>
#include <vector>
typedef unsigned long long ull;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string pw;
    cin >> pw;
    vector<int> dp(pw.size() + 1);
    if (pw[0] == '0')
    {
        cout << 0;
        return 0;
    }
    dp[0] = 1, dp[1] = 1;
    for (int i = 1; i < pw.size(); ++i)
    {
        if (pw[i] == '0')
        {
            if (pw[i - 1] <= '2' && pw[i - 1] > '0')
            {
                dp[i + 1] = dp[i - 1];
            }
            else
            {
                cout << 0;
                return 0;
            }
        }
        else
        {
            if (((pw[i - 1] == '2' && pw[i] <= '6') || (pw[i - 1] < '2')) && pw[i - 1] > '0')
            {
                dp[i + 1] = (dp[i] + dp[i - 1]) % 1000000;
            }
            else
            {
                dp[i + 1] = dp[i];
            }
        }
    }
    cout << dp[pw.size()];
}