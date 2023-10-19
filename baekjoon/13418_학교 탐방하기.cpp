#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, A, B, C, high = 0, low = 0;
    cin >> N >> M;
    vector<vector<pii>> graph(N + 1, vector<pii>());
    vector<bool> isVisited(N + 1);
    priority_queue<pii> hq;
    priority_queue<pii, vector<pii>, greater<pii>> lq;
    for (int i = 0; i <= M; ++i)
    {
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    isVisited[0] = true;
    for (pii next : graph[0])
        hq.push({next.second, next.first});
    while (!hq.empty())
    {
        pii cur = hq.top();
        hq.pop();
        int curNode = cur.second;
        int curStep = cur.first;
        if (isVisited[curNode])
            continue;
        isVisited[curNode] = true;
        if (!curStep)
            ++high;
        for (pii next : graph[curNode])
        {
            int nextNode = next.first;
            int nextStep = next.second;
            if (isVisited[nextNode])
                continue;
            hq.push({nextStep, nextNode});
        }
    }

    isVisited[0] = false;
    for (pii next : graph[0])
        lq.push({next.second, next.first});
    while (!lq.empty())
    {
        pii cur = lq.top();
        lq.pop();
        int curNode = cur.second;
        int curStep = cur.first;
        if (!isVisited[curNode])
            continue;
        isVisited[curNode] = false;
        if (!curStep)
            ++low;
        for (pii next : graph[curNode])
        {
            int nextNode = next.first;
            int nextStep = next.second;
            if (!isVisited[nextNode])
                continue;
            lq.push({nextStep, nextNode});
        }
    }
    cout << low * low - high * high;
    return 0;
}