#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int N, M, A, B, C, answer, maxValue;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<vector<pii>> graph;
vector<bool> isVisited;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    isVisited = vector<bool>(N + 1);
    graph = vector<vector<pii>>(N + 1, vector<pii>());

    while (M--)
    {
        cin >> A >> B >> C;

        graph[A].push_back({C, B});
        graph[B].push_back({C, A});
    }

    isVisited[1] = true;
    for (pii next : graph[1])
    {
        pq.push(next);
    }

    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();

        int value = cur.first;
        int index = cur.second;

        if (isVisited[index])
        {
            continue;
        }

        isVisited[index] = true;
        answer += value;
        maxValue = max(maxValue, value);

        for (pii next : graph[index])
        {
            if (isVisited[next.second])
            {
                continue;
            }

            pq.push(next);
        }
    }

    cout << answer - maxValue;
    return 0;
}