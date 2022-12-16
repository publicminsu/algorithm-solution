#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    while (N--)
    {
        int W, V;
        cin >> W >> V;
        for (int i = K; i >= W; --i)
        {
            dp[i] = max(dp[i], dp[i - W] + V);
        }
    }
    cout << dp[K];
    return 0;
}