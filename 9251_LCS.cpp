#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string str1, str2;
    cin >> str1 >> str2;
    vector<vector<int>> dp(str2.size() + 1, vector<int>(str1.size() + 1, 0));
    for (int i = 1; i <= str2.length(); ++i)
        for (int j = 1; j <= str1.length(); ++j)
        {
            if (str1[j - 1] == str2[i - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    cout << dp[str2.size()][str1.size()];
    return 0;
}