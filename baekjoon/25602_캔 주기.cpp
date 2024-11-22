#include <iostream>
using namespace std;
int N, K, answer;
int A[5], RM[8][5];

void dfs(int day, int sum)
{
    if (day == K * 2)
    {
        answer = max(sum, answer);

        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (!A[i])
        {
            continue;
        }

        --A[i];
        dfs(day + 1, sum + RM[day][i]);
        ++A[i];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    for (int i = 0; i < K * 2; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> RM[i][j];
        }
    }

    dfs(0, 0);

    cout << answer;
    return 0;
}