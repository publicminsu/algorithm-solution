#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<vector<int>>> dp;
string str[3];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str[0] >> str[1] >> str[2];
    dp = vector<vector<vector<int>>>(str[0].length() + 1, vector<vector<int>>(str[1].length() + 1, vector<int>(str[2].length() + 1)));
    for (int i = 1; i <= str[0].length(); ++i)
    {
        for (int j = 1; j <= str[1].length(); ++j)
        {
            for (int k = 1; k <= str[2].length(); ++k)
            {
                if (str[0][i - 1] == str[1][j - 1] && str[1][j - 1] == str[2][k - 1])
                {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
    }
    cout << dp[str[0].length()][str[1].length()][str[2].length()];
    return 0;
}