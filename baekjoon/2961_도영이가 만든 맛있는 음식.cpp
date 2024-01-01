#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> taste;
int N, answer = 1000000000;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    taste = vector<vector<int>>(2, vector<int>(N));

    for (int i = 0; i < N; ++i)
    {
        cin >> taste[0][i] >> taste[1][i];
    }
}
void dfs(int idx, int multi, int sum, bool isUsing)
{
    if (idx == N) // 끝에 도달했는지?
    {
        if (isUsing) // 값을 사용했는지?
        {
            answer = min(answer, abs(multi - sum));
        }
        return;
    }
    dfs(idx + 1, multi, sum, isUsing);
    dfs(idx + 1, multi * taste[0][idx], sum + taste[1][idx], true);
}
int main()
{
    input();
    dfs(0, 1, 0, false);
    cout << answer;
    return 0;
}