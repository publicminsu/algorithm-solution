#include <iostream>
#include <cstring>
using namespace std;
bool map[1001][1001];
int dp[1001][1001];
int N, M, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        cin >> N >> M;
        if (!N)
        {
            break;
        }
        answer = 0;

        memset(dp, 0, sizeof(dp));

        for (int y = 1; y <= N; ++y)
        {
            for (int x = 1; x <= M; ++x)
            {
                cin >> map[y][x];
                if (map[y][x]) // 만약 1이라면
                {
                    dp[y][x] = min(dp[y - 1][x - 1], min(dp[y - 1][x], dp[y][x - 1])) + 1; // 가장 작은 정사각형을 이어나감
                    answer = max(answer, dp[y][x]);
                }
            }
        }

        cout << answer << "\n";
    }

    return 0;
}