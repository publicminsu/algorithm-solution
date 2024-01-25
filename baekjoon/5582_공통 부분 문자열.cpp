#include <iostream>
#include <vector>
using namespace std;
string str1, str2;
vector<vector<int>> dp;
int answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> str1 >> str2;
    dp = vector<vector<int>>(str1.size() + 1, vector<int>(str2.size() + 1));

    for (int i = 0; i < str1.size(); ++i)
    {
        for (int j = 0; j < str2.size(); ++j)
        {
            if (str1[i] == str2[j]) // 동일한 경우
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                answer = max(answer, dp[i + 1][j + 1]);
            }
        }
    }
    cout << answer;
    return 0;
}