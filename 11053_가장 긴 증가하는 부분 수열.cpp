#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, ret = 0;
    cin >> N;
    vector<int> A(N), dp(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (A[i] > A[j])
            {
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
        }
        ret = ret > dp[i] ? ret : dp[i];
    }
    cout << ret;
}