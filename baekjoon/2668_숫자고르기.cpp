#include <iostream>
#include <vector>
using namespace std;
vector<bool> isVisted;
vector<int> graph, ret;
void dfs(int cur, int start)
{
    if (isVisted[cur])
    {
        if (cur == start)
            ret.push_back(cur);
    }
    else
    {
        isVisted[cur] = true;
        dfs(graph[cur], start);
    }
}
int main()
{
    int N;
    cin >> N;
    graph = vector<int>(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> graph[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        isVisted = vector<bool>(N + 1);
        dfs(i, i);
    }
    cout << ret.size();
    for (int i : ret)
    {
        cout << "\n"
             << i;
    }
}