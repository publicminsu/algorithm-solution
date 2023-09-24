#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int time1, money1, time2, money2;
};
vector<node> v;
int N, K;
vector<vector<int>> dp;
int recur(int n, int k)
{
    if (k < 0)
        return -100000000;
    else if (n == N)
        return 0;
    if (dp[n][k])
        return dp[n][k];
    return dp[n][k] = max((recur(n + 1, k - v[n].time1) + v[n].money1), (recur(n + 1, k - v[n].time2) + v[n].money2));
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    v = vector<node>(N);
    dp = vector<vector<int>>(N, vector<int>(K + 1));
    for (int i = 0; i < N; ++i)
        cin >> v[i].time1 >> v[i].money1 >> v[i].time2 >> v[i].money2;
    cout << recur(0, K);
    return 0;
}