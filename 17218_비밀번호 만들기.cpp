#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string word1, word2, ret;
    cin >> word1 >> word2;
    vector<vector<string>> dp(word1.length() + 1, vector<string>(word2.length() + 1));
    for (int i = 0; i < word1.length(); ++i)
        for (int j = 0; j < word2.length(); ++j)
        {
            if (word1[i] == word2[j])
                dp[i + 1][j + 1] = dp[i][j] + word1[i];
            else
                dp[i + 1][j + 1] = dp[i + 1][j].length() > dp[i][j + 1].length() ? dp[i + 1][j] : dp[i][j + 1];
        }
    cout << dp[word1.length()][word2.length()];
    return 0;
}