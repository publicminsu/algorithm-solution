#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int N, sum = 0;
    scanf("%d", &N);
    vector<vector<int>> dp(N, vector<int>(10, 1));
    for (int i = 1; i < N; ++i)
    {
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j < 9; ++j)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
        dp[i][9] = dp[i - 1][8];
    }
    for (int i = 1; i <= 9; ++i)
    {
        sum = (sum + dp[N - 1][i]) % 1000000000;
    }
    printf("%d", sum);
    return 0;
}