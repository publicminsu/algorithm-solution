#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>> graph;
vector<bool> isVisited;
int ret;
int dfs(int cur)
{
    int cnt = 0, sum = 0;
    isVisited[cur] = true;
    vector<int> buffer;
    for (pii next : graph[cur])
        if (!isVisited[next.first])
        {
            int child = dfs(next.first) + next.second;
            cnt = max(child, cnt);
            buffer.push_back(child);
        }
    if (buffer.size() <= 2)
        for (int i : buffer)
            sum += i;
    else
    {
        sort(buffer.begin(), buffer.end(), greater<int>());
        sum = buffer[0] + buffer[1];
    }
    ret = max(ret, sum);
    return cnt;
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, a, b, c;
    cin >> n;
    graph = vector<vector<pii>>(n + 1, vector<pii>());
    isVisited = vector<bool>(n + 1);
    while (--n)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}
int main()
{
    input();
    dfs(1);
    cout << ret;
    return 0;
}