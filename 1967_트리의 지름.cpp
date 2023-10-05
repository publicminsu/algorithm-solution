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
            // DFS를 마친 값을 저장해 줘야 한다. (얼마나 긴 값인지 알아야 하므로)
            buffer.push_back(child);
        }
    if (buffer.size() <= 2) // 2개 이하인가?
        for (int i : buffer)
            sum += i;
    else
    {
        // 2개 이상이면 가장 큰 2개의 값을 더해준다.
        sort(buffer.begin(), buffer.end(), greater<int>());
        sum = buffer[0] + buffer[1];
    }
    // 가장 긴 트리의 지름인지 확인해 준다.
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