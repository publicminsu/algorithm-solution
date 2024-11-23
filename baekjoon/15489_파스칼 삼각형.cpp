#include <iostream>
using namespace std;
#define SIZE 31
int R, C, W;
long long answer;
int dp[SIZE][SIZE];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> R >> C >> W;
    --R, --C;

    for (int i = 0; i < SIZE; ++i)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < SIZE; ++i)
    {
        for (int j = 1; j < SIZE; ++j)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    for (int i = R; i < R + W; ++i)
    {
        for (int j = C; j < C + i - R + 1; ++j)
        {
            answer += dp[i][j];
        }
    }

    cout << answer;
    return 0;
}