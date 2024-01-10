#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> graph;
vector<int> order;
int N;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    graph = vector<vector<int>>(N + 1, vector<int>());
    order = vector<int>(N);
    for (int i = 1, a, b; i < N; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int &i : order)
    {
        cin >> i;
    }
}
bool solve()
{
    stack<int> s;
    s.push(1);
    for (int i = 1; i < N; ++i)
    {
        while (!s.empty()) // 스택이 비어있지 않다면
        {
            bool isFind = false;
            for (int j : graph[s.top()]) // 인접한 정점
            {
                if (order[i] == j) // 순서와 정점이 일치하면 가능한 것
                {
                    isFind = true;
                    break;
                }
            }
            if (isFind) // 가능하다면 스택에 집어넣기
            {
                s.push(order[i]);
                break;
            }
            else // 불가능하면 현재 정점의 부모로 돌아가기
            {
                s.pop();
            }
        }
        if (s.empty()) // 1번 정점에서도 불가능한 것
        {
            return false;
        }
    }
    return true;
}
int main()
{
    input();
    cout << solve();
    return 0;
}