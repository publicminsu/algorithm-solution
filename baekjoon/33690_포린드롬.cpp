#include <iostream>
using namespace std;

using ll = long long;

int N, answer;

void dfs(ll num, ll i)
{
    if (num > N)
    {
        return;
    }

    ++answer;

    dfs(num * 10 + i, i);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 1; i <= 9; ++i)
    {
        dfs(i, i);
    }

    cout << answer + 1;

    return 0;
}