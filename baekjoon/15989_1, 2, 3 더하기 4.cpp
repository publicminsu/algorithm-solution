#include <iostream>
using namespace std;
int main()
{
    int T, min = 0;
    cin >> T;
    int dp[3][10001];
    int numbers[] = {2, 3};
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = min; i <= n; ++i)
        {
            dp[0][i] = 1;
            for (int number : numbers)
            {
                if (i - number >= 0)
                    dp[number - 1][i] = dp[number - 1][i - number] + dp[number - 2][i];
                else
                    dp[number - 1][i] = dp[number - 2][i];
            }
        }
        cout << dp[2][n] << "\n";
        if (min < n)
            min = n;
    }
    return 0;
}