#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int n, m, startCity, endCity;
vector<vector<pii>> startGraph;
vector<vector<int>> parents;
vector<int> isVisited;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    startGraph = vector<vector<pii>>(n + 1, vector<pii>());
    isVisited = vector<int>(n + 1, -1);
    parents = vector<vector<int>>(n + 1, vector<int>());
    while (m--)
    {
        int city1, city2, time;
        cin >> city1 >> city2 >> time;
        startGraph[city1].push_back({time, city2});
    }
    cin >> startCity >> endCity;
}
void dijkstra()
{
    priority_queue<tiii> pq;
    pq.push({0, startCity, 0});
    while (!pq.empty())
    {
        tiii cur = pq.top();
        pq.pop();
        int value = get<0>(cur);
        int index = get<1>(cur);
        int parent = get<2>(cur);
        if (isVisited[index] != -1 && isVisited[index] >= value)
        {
            if (isVisited[index] == value)
                parents[index].push_back(parent);
            continue;
        }
        parents[index].clear();
        parents[index].push_back(parent);
        isVisited[index] = value;
        for (pii node : startGraph[index])
        {
            if (isVisited[node.second] != -1 && isVisited[node.second] > isVisited[index] + node.first)
                continue;
            pq.push({value + node.first, node.second, index});
        }
    }
}
int dfs(int cur)
{
    if (cur == startCity || !isVisited[cur])
        return 0;
    isVisited[cur] = 0;
    int ret = 0;
    for (int next : parents[cur])
        ret += dfs(next) + 1;
    return ret;
}
int main()
{
    input();
    dijkstra();
    cout << isVisited[endCity] << "\n";
    cout << dfs(endCity);
    return 0;
}