#include <iostream>
#include <string>
#include <vector>
using namespace std;
string A, B;
vector<vector<int>> dp;
int aSize, bSize;
// 값이 오른 부분 추적
void recur(int y, int x)
{
    if (x == 0 || y == 0) // 끝에 도달한 경우
        return;
    if (dp[y][x] == dp[y - 1][x - 1] + 1 && dp[y][x] == dp[y - 1][x] + 1 && dp[y][x] == dp[y][x - 1] + 1) // 오른쪽, 왼쪽 값 가져온 경우 제외
    {
        recur(y - 1, x - 1);
        cout << A[y - 1];
    }
    else
    {
        if (dp[y][x - 1] > dp[y - 1][x]) // 이어온 값을 추적
            recur(y, x - 1);
        else
            recur(y - 1, x);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B;
    aSize = A.size(), bSize = B.size();
    dp = vector<vector<int>>(aSize + 1, vector<int>(bSize + 1));
    for (int i = 1; i <= aSize; ++i)
        for (int j = 1; j <= bSize; ++j)
            if (A[i - 1] == B[j - 1]) // 같다면 대각선에서 가져오기
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    cout << dp[aSize][bSize] << "\n";
    recur(aSize, bSize);
    return 0;
}