#include <iostream>
#include <vector>
using namespace std;
int N, answer;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    dp = vector<int>(N + 1);

    for (int i = 0, T, P; i < N; ++i)
    {
        cin >> T >> P;

        if (i + T > N)
        {
            continue;
        }

        for (int j = 0; j <= i; ++j)
        {
            int &k = dp[i + T];
            k = max(k, dp[j] + P);
            answer = max(k, answer);
        }
    }

    cout << answer;
    return 0;
}