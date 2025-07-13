#include <iostream>
#include <cstring>

using namespace std;

#define MOD 1000000007

int dp[2][3][101][10];
int N, answer;

int dfs(bool isIncrease, int length, int idx, int num)
{
    if (num < 0 || num > 9)
    {
        return 0;
    }

    if (length >= 3)
    {
        return 0;
    }

    if (idx == N)
    {
        return 1;
    }

    int &value = dp[isIncrease][length][idx][num];

    if (value != -1)
    {
        return value;
    }

    value = 0;

    for (int i = 0; i < 2; ++i)
    {
        int nextLength = i == isIncrease ? length + 1 : 1;
        int nextNum = i ? num + 1 : num - 1;

        value = (value + dfs(i, nextLength, idx + 1, nextNum)) % MOD;
    }

    return value;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N;

    if (N == 1)
    {
        answer = 10;
    }
    else
    {
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                int nextNum = i ? j + 1 : j - 1;

                answer = (answer + dfs(i, 1, 2, nextNum)) % MOD;
            }
        }
    }

    cout << answer;
    return 0;
}