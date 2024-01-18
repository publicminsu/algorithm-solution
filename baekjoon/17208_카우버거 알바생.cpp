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
                int nextDP = dp[j - burger][k - fry] + 1; // 치즈버거, 감자튀김의 요구 개수를 감당할 수 있는 값
                if (nextDP > dp[j][k])                    // 새로운 값이 이전 값보다 크다면
                {
                    dp[j][k] = nextDP;
                    answer = max(answer, dp[j][k]);
                }
            }
        }
    }
    cout << answer;
    return 0;
}