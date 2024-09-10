#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> score, dp;
int main()
{
    cin >> N;

    score = dp = vector<int>(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        cin >> score[i];

        int maxScore = score[i];
        int minScore = score[i];

        for (int j = i - 1; j >= 0; --j)
        {
            maxScore = max(maxScore, score[j + 1]);
            minScore = min(minScore, score[j + 1]);
            dp[i] = max(dp[i], dp[j] + maxScore - minScore);
        }
    }

    cout << dp[N];
    return 0;
}