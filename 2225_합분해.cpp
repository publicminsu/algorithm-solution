#include <iostream>
#include <vector>
typedef unsigned long long ull;
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<ull>> dp(N + 1, vector<ull>(K + 1, 1));
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 2; j <= K; ++j)
        {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
        }
    }
    cout << dp[N][K];
}