#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
int N, T, K, S;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> T;

    dp = vector<int>(T + 1);

    for (int i = 0; i < N; ++i)
    {
        cin >> K >> S;

        for (int j = T; j >= K; --j)
        {
            dp[j] = max(dp[j], dp[j - K] + S);
        }
    }

    cout << dp[T];
    return 0;
}