#include <iostream>
using namespace std;

#define INF 987654321

int n;
int prefixSum[3001];
int dp[3001];

int recur(int idx)
{
    if (idx > n)
    {
        return 0;
    }

    int &value = dp[idx];

    if (value != INF)
    {
        return value;
    }

    for (int i = idx; i <= n; ++i)
    {
        value = min(value, (prefixSum[i] - prefixSum[idx - 1]) - recur(i + 1));
    }

    return value;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    for (int tc = 0; tc < 3; ++tc)
    {
        for (int i = n; i >= 1; --i)
        {
            cin >> prefixSum[i];
            dp[i] = INF;
        }

        for (int i = 2; i <= n; ++i)
        {
            prefixSum[i] += prefixSum[i - 1];
        }

        int value = recur(1);

        if (value < 0)
        {
            cout << "A";
        }
        else if (value == 0)
        {
            cout << "D";
        }
        else
        {
            cout << "B";
        }

        cout << "\n";
    }
    return 0;
}