#include <iostream>
#include <vector>
using namespace std;
vector<int> nums;
vector<vector<int>> dp;
int N, M;
void makeDP()
{
    for (int i = 0; i < N; ++i) // 1칸인 경우
    {
        dp[i][i] = 1;
        if (i + 1 < N) // 2칸이 가능한 경우
        {
            if (nums[i] == nums[i + 1]) // 2칸이면서 숫자가 같은 경우
            {
                dp[i][i + 1] = 1;
            }
        }
    }
    for (int start = N - 1; start >= 0; --start)
    {
        for (int end = start + 2; end < N; ++end) // 2칸까지는 확인했기에 3칸부터
        {
            if (nums[start] == nums[end] && dp[start + 1][end - 1]) // 숫자가 같은 경우, 내부가 팰린드롬인 경우
            {
                dp[start][end] = 1;
            }
        }
    }
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    nums = vector<int>(N);
    dp = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
    makeDP();
    cin >> M;
    while (M--)
    {
        int S, E;
        cin >> S >> E;
        cout << dp[S - 1][E - 1] << "\n";
    }
}
int main()
{
    input();
    return 0;
}