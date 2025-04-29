#include <iostream>
#include <vector>
using namespace std;

int N, p;
string words[500001];
vector<int> childs[500001];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> words[i];
    }

    for (int i = 0, c; i < N - 1; ++i)
    {
        cin >> p >> c;

        childs[p].push_back(c);
    }
}

void dfs(int cur)
{
    cout << words[cur];

    for (const int &child : childs[cur])
    {
        dfs(child);
    }
}

int main()
{
    input();
    dfs(p);
    return 0;
}