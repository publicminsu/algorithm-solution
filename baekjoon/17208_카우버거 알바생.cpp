#include <iostream>
#include <vector>
using namespace std;
int N, M, K, answer;
vector<vector<int>> dp;
vector<int> burgers, fries;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;

    dp = vector<vector<int>>(M + 1, vector<int>(K + 1));
    burgers = fries = vector<int>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> burgers[i] >> fries[i];
    }

    for (int i = 0; i < N; ++i)
    {
        int burger = burgers[i];
        int fry = fries[i];

        for (int j = M; j >= burger; --j)
        {
            for (int k = K; k >= fry; --k)
            {
                dp[j][k] = max(dp[j][k], dp[j - burger][k - fry] + 1); // 유지하기 vs 요구 개수 챙기기
                answer = max(answer, dp[j][k]);
            }
        }
    }
    cout << answer;
    return 0;
}