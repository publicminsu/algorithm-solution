#include <iostream>
#include <vector>
using namespace std;
int n, s, answer;
vector<int> v;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    v = vector<int>(n);
    for (int &i : v)
    {
        cin >> i;
    }
    cin >> s;
}
void dfs(int cur)
{
    if (cur >= n || cur < 0 || v[cur] == -1)
    {
        return;
    }
    int jump = v[cur];
    v[cur] = -1;
    ++answer;

    dfs(cur + jump);
    dfs(cur - jump);
}
int main()
{
    input();
    dfs(s - 1);
    cout << answer;
    return 0;
}