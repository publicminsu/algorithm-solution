#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    int child, len;
};
vector<vector<node>> tree;
vector<bool> isVisited;
int V, ret = 0;
int dfs(int cur)
{
    vector<int> v;
    for (node next : tree[cur])
    {
        if (isVisited[next.child])
        {
            continue;
        }
        isVisited[next.child] = true;
        v.push_back(dfs(next.child) + next.len);
    }
    sort(v.begin(), v.end(), greater<int>()); // 정렬
    if (v.empty())
    {
        return 0;
    }
    else
    {
        if (v.size() >= 2) // 자식이 2개 이상이라면
        {
            ret = max(ret, v[0] + v[1]);
        }
        return v.front(); // 가장 긴 선분 반환
    }
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> V;
    isVisited = vector<bool>(V + 1);
    tree = vector<vector<node>>(V + 1, vector<node>());
    for (int i = 0, start, end, len; i < V; ++i)
    {
        cin >> start;
        while (true)
        {
            cin >> end;
            if (end == -1)
            {
                break;
            }
            cin >> len;
            tree[start].push_back({end, len});
        }
    }
}
int main()
{
    input();
    isVisited[1] = true;
    ret = max(dfs(1), ret);
    cout << ret;
    return 0;
}