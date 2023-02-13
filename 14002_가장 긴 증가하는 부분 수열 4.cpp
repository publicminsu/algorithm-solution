#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, maxIdx = 0, maxSize = 0;
    cin >> N;
    vector<int> A, dp(N), ret;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        A.push_back(a);
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (A[i] > A[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (dp[i] > maxSize)
        {
            maxSize = dp[i];
            maxIdx = i;
        }
    }
    cout << maxSize << "\n";
    for (int i = maxIdx; i >= 0; --i)
    {
        if (dp[i] == maxSize)
        {
            ret.push_back(A[i]);
            --maxSize;
        }
    }
    for (int i = ret.size() - 1; i >= 0; --i)
    {
        cout << ret[i] << " ";
    }
}