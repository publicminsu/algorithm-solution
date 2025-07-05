#include <iostream>
using namespace std;
int years[3] = {1, 3, 5};
double rates[3] = {1.05, 1.2, 1.35};
int dp[11];
int H, Y;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> H >> Y;
    dp[0] = H;

    for (int i = 1; i <= Y; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i - years[j] < 0)
            {
                continue;
            }

            dp[i] = max(dp[i], (int)(dp[i - years[j]] * rates[j]));
        }
    }

    cout << dp[Y];
    return 0;
}