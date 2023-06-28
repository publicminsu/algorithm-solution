#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string word;
    cin >> word;
    int cnt = 0, len = word.length();
    vector<int> dp(len);

    for (int i = 0; i < len; ++i)
    {
        if (word[i] == '(')
            dp[i] = 1;
        else
            dp[i] = -1;
    }

    for (int i = 1; i < len; ++i)
        dp[i] += dp[i - 1];

    if (dp[len - 1] == 2)
        for (int i = len - 1; i >= 0; --i)
        {
            if (dp[i] == 1)
                break;
            if (word[i] == '(')
                ++cnt;
        }
    else if (dp[len - 1] == -2)
        for (int i = 0; i < len; ++i)
        {
            if (word[i] == ')')
                ++cnt;
            if (dp[i] == -1)
                break;
        }
    cout << cnt;
    return 0;
}