#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
#define COLOR_LEN 3
vector<vector<int>> house, dp;
int N;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    house = dp = vector<vector<int>>(N, vector<int>(COLOR_LEN));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> house[i][j];
        }
    }
}
void solve()
{
    int answer = INF;
    for (int start = 0; start < COLOR_LEN; ++start)
    {
        fill(dp.begin(), dp.end(), vector<int>(COLOR_LEN, INF)); // dp 초기화

        dp[0][start] = house[0][start];

        for (int idx = 0; idx < N - 1; ++idx)
        {
            for (int curColor = 0; curColor < COLOR_LEN; ++curColor)
            {
                for (int nextColor = 0; nextColor < COLOR_LEN; ++nextColor)
                {
                    if (curColor == nextColor || ((idx == N - 2) && (nextColor == start))) // 현재와 다음이 같거나 시작과 끝이 같은 경우
                    {
                        continue;
                    }

                    int &nextDP = dp[idx + 1][nextColor];
                    nextDP = min(nextDP, dp[idx][curColor] + house[idx + 1][nextColor]);
                }
            }
        }
        for (const int &lastHouse : dp[N - 1]) // 가장 작은 값 확인
        {
            answer = min(answer, lastHouse);
        }
    }
    cout << answer;
}
int main()
{
    input();
    solve();
    return 0;
}