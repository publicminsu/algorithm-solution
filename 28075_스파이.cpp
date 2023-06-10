#include <iostream>
#include <queue>
using namespace std;
int progress[2][3], N, M, ret = 0;
void dfs(int day, int sum, int prevJ)
{
    if (day == N)
    {
        if (sum >= M)
            ++ret;
        return;
    }
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
        {
            int nextSum = sum;
            if (j == prevJ)
                nextSum += progress[i][j] / 2;
            else
                nextSum += progress[i][j];
            dfs(day + 1, nextSum, j);
        }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> progress[i][j];
    dfs(0, 0, -1);
    cout << ret;
    return 0;
}