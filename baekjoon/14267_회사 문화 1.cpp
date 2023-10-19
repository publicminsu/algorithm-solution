#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<vector<int>> childs;
vector<int> prefix;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    childs = vector<vector<int>>(n + 1, vector<int>());
    prefix = vector<int>(n + 1);

    int i, j;
    cin >> i; // 사장의 -1 버리기

    for (i = 2; i <= n; ++i) // 사장 없기에 2부터 n까지
    {
        cin >> j;
        childs[j].push_back(i);
    }

    while (m--) // 칭찬 적용
    {
        cin >> i >> j;
        prefix[i] += j;
    }
}
void dfs(int cur) // 자식으로 내려가며 누적 합
{
    for (int next : childs[cur])
    {
        prefix[next] += prefix[cur];
        dfs(next);
    }
}
int main()
{
    input();
    dfs(1);

    for (int i = 1; i <= n; ++i)
    {
        cout << prefix[i] << " ";
    }
    return 0;
}