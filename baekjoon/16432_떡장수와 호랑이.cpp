#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ricecakes;
vector<vector<bool>> visted;
vector<int> v;
int N;
void dfs(int day, int prev)
{
    if (day == N + 1)
    {
        for (int i = 1; i <= N; ++i)
            cout << v[i] << "\n";
        exit(0);
    }
    for (int i : ricecakes[day])
    {
        if (i == prev || visted[day][i])
            continue;
        visted[day][i] = true;
        v[day] = i;
        dfs(day + 1, i);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    ricecakes = vector<vector<int>>(N + 1, vector<int>());
    visted = vector<vector<bool>>(N + 1, vector<bool>(10));
    v = vector<int>(N + 1);
    for (int i = 1, j, k; i <= N; ++i)
    {
        cin >> j;
        while (j--)
        {
            cin >> k;
            ricecakes[i].push_back(k);
        }
    }
    dfs(1, 0);
    cout << -1;
    return 0;
}