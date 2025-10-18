#include <iostream>
#include <vector>
using namespace std;

#define MAX_SIZE 10080

struct program
{
    int s, d, p;
};

int t, n;
int dp[MAX_SIZE + 1];
vector<program> programs[MAX_SIZE + 1];

void clear()
{
    for (int i = 0; i <= MAX_SIZE; ++i)
    {
        dp[i] = 0;
        programs[i].clear();
    }
}

void solve()
{
    cin >> n;

    while (n--)
    {
        program program;
        cin >> program.s >> program.d >> program.p;

        programs[program.s + program.d].push_back(program);
    }

    for (int i = 0; i <= MAX_SIZE; ++i)
    {
        dp[i] = dp[i - 1];

        for (program p : programs[i])
        {
            dp[i] = max(dp[i], dp[p.s] + p.p);
        }
    }

    cout << dp[MAX_SIZE] << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--)
    {
        clear();
        solve();
    }
}