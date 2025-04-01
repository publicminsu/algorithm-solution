#include <iostream>
using namespace std;

using ll = long long;

ll dp[2][200000];
int cards[2][200000];
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> cards[i][j];
        }
    }

    dp[0][0] = cards[0][0] + max(0, cards[1][0]);
    dp[1][0] = cards[0][0] + cards[1][0];

    for (int i = 1; i < N; ++i)
    {
        for (int my = 0; my < 2; ++my)
        {
            int other = (my + 1) % 2;

            dp[my][i] = dp[my][i - 1] + cards[my][i] + max(0, cards[other][i]);
            dp[my][i] = max(dp[my][i], dp[other][i - 1] + cards[my][i] + cards[other][i]);
        }
    }

    cout << dp[1][N - 1];
    return 0;
}