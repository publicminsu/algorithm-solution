#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp;
vector<int> names;
int n, m;

int dfs(int index, int count)
{
    if (index == n)
    {
        return 0;
    }

    if (dp[index][count] != -1)
    {
        return dp[index][count];
    }

    int diff = m - count;
    dp[index][count] = dfs(index + 1, names[index]) + diff * diff;

    int nextCount = count + 1 + names[index];
    if (nextCount <= m)
    {
        dp[index][count] = min(dp[index][count], dfs(index + 1, nextCount));
    }

    return dp[index][count];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
    names = vector<int>(n);
    for (int &name : names)
    {
        cin >> name;
    }

    cout << dfs(1, names[0]);

    return 0;
}