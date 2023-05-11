#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string dp[101][101];

string addString(string num1, string num2)
{
    int sum = 0;
    string ret;
    while (!num1.empty() || !num2.empty() || sum)
    {
        if (!num1.empty())
        {
            sum += num1.back() - '0';
            num1.pop_back();
        }
        if (!num2.empty())
        {
            sum += num2.back() - '0';
            num2.pop_back();
        }
        ret.push_back(sum % 10 + '0');
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string comb(int n, int m)
{
    if (n == m || m == 0)
        return "1";

    if (!dp[n][m].empty())
        return dp[n][m];

    return dp[n][m] = addString(comb(n - 1, m - 1), comb(n - 1, m));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    cout << comb(n, m);
    return 0;
}