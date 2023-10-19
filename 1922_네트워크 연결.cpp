#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> tiii;
vector<tiii> graph;
vector<int> parents;
int findParent(int cur)
{
    if (parents[cur])
        return parents[cur] = findParent(parents[cur]); // 부모 경로 단축
    else
        return cur;
}
void unionParent(int a, int b) // 부모 합치기
{
    a = findParent(a);
    b = findParent(b);
    parents[a] = b;
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, a, b, c;
    cin >> N >> M;

    parents = vector<int>(N + 1);
    while (M--)
    {
        cin >> a >> b >> c;
        graph.push_back({c, a, b});
    }
}
void kruskal()
{
    int sum = 0;

    sort(graph.begin(), graph.end());
    for (tiii node : graph)
    {
        int a = get<1>(node);
        int b = get<2>(node);
        if (findParent(a) != findParent(b)) // 부모가 같지 않다면
        {
            unionParent(a, b);
            sum += get<0>(node);
        }
    }
    cout << sum;
}
int main()
{
    input();
    kruskal();
    return 0;
}