#include <iostream>
#include <string>
using namespace std;
int idx = 0, n, k;
string ret;
int dx[] = {1, 2, 3};
void dfs(int sum, string exp)
{
    if (sum == n)
    {
        ++idx;
        if (idx == k)
        {
            cout << exp;
            exit(0);
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        int nextSum = sum + dx[i];
        if (nextSum <= n)
        {
            string nextExp = exp + to_string(dx[i]) + (nextSum < n ? "+" : "");
            dfs(nextSum, nextExp);
        }
    }
}
int main()
{
    cin >> n >> k;
    dfs(0, "");
    cout << -1;
    return 0;
}