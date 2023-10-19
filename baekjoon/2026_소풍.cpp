#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int K, N, F;
vector<vector<int>> graph;
vector<vector<bool>> isFriend;
vector<bool> isVisited;
vector<int> picnic;
bool friendCheck()
{
    for (int i = 0; i < picnic.size(); ++i)
        for (int j = i + 1; j < picnic.size(); ++j)
            if (!isFriend[picnic[i]][picnic[j]])
                return false;
    return true;
}
void dfs(int cur, int depth)
{
    if (K == depth)
    {
        if (friendCheck())
        {
            for (int i : picnic)
                cout << i << "\n";
            exit(0);
        }
        return;
    }
    for (int next : graph[cur])
    {
        if (graph[next].size() < K - 1 || isVisited[next])
            continue;
        isVisited[next] = true;
        picnic.push_back(next);
        dfs(next, depth + 1);
        picnic.pop_back();
        isVisited[next] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> K >> N >> F;
    graph = vector<vector<int>>(N + 1, vector<int>());
    isFriend = vector<vector<bool>>(N + 1, vector<bool>(N + 1));
    isVisited = vector<bool>(N + 1);
    while (F--)
    {
        int i, j;
        cin >> i >> j;
        graph[i].push_back(j);
        graph[j].push_back(i);
        isFriend[i][j] = isFriend[j][i] = true;
    }
    for (int i = 1; i <= N; ++i)
    {
        if (graph[i].size() < K - 1)
            continue;
        sort(graph[i].begin(), graph[i].end());
    }
    for (int i = 1; i <= N; ++i)
    {
        if (graph[i].size() < K - 1)
            continue;
        isVisited[i] = true;
        picnic.push_back(i);
        dfs(i, 1);
        picnic.pop_back();
        isVisited[i] = false;
    }
    cout << -1;
    return 0;
}