#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool notPrime[10000000] = {true, true}, visited[10000000], used[8];
int c, answer;
string num;
void dfs(int index, string comb)
{
    if (index == num.size())
    {
        int cur = stoi(comb);
        if (visited[cur] || notPrime[cur])
        {
            return;
        }

        visited[cur] = true;
        ++answer;
        return;
    }

    for (int i = 0; i < num.size(); ++i)
    {
        if (used[i])
        {
            continue;
        }
        used[i] = true;
        dfs(index + 1, comb + num[i]);
        used[i] = false;
    }
    dfs(index + 1, comb);
}
void init()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> c;

    for (int i = 2; i * i < 10000000; ++i)
    {
        if (notPrime[i])
        {
            continue;
        }

        for (int j = i + i; j < 10000000; j += i)
        {
            notPrime[j] = true;
        }
    }
}
void solve()
{
    while (c--)
    {
        memset(visited, false, sizeof(visited));
        answer = 0;
        cin >> num;

        dfs(0, "0");

        cout << answer << "\n";
    }
}
int main()
{
    init();
    solve();
    return 0;
}