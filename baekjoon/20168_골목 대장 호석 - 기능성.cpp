#include <iostream>
#include <map>
#include <vector>

using namespace std;
using pii = pair<int, int>;

#define INF 987654321

int N, M, A, B, C;
map<int, vector<pii>> graph;
bool isVisited[11];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> A >> B >> C;
    while (M--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }
}

void backtracking(int curIndex, int sum, int maxCost, int &result)
{
    if (sum > C)
    {
        return;
    }

    if (maxCost >= result)
    {
        return;
    }

    if (curIndex == B)
    {
        result = min(result, maxCost);
        return;
    }

    for (pii nextNode : graph[curIndex])
    {
        int nextIndex = nextNode.first;
        int nextCost = nextNode.second;

        if (isVisited[nextIndex])
        {
            continue;
        }

        isVisited[nextIndex] = true;
        backtracking(nextIndex, nextCost + sum, max(nextCost, maxCost), result);
        isVisited[nextIndex] = false;
    }
}

int main()
{
    input();

    int result = INF;

    isVisited[A] = true;
    backtracking(A, 0, 0, result);

    if (result == INF)
    {
        result = -1;
    }

    cout << result;
    return 0;
}