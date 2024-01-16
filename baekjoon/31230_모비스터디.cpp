#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;
vector<vector<pli>> graph;
vector<vector<int>> returnPath;
vector<ll> dist;
vector<int> path;
vector<bool> isVisited;
int N, M, A, B;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> A >> B;

    graph = vector<vector<pli>>(N + 1, vector<pli>());
    dist = vector<ll>(N + 1);
    isVisited = vector<bool>(N + 1);
    returnPath = vector<vector<int>>(N + 1, vector<int>());

    int a, b, c;
    while (M--)
    {
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
}
void dijkstra()
{
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    isVisited[A] = true;
    pq.push({0, A});

    while (!pq.empty())
    {
        pli cur = pq.top();
        pq.pop();

        if (dist[cur.second] < cur.first)
        {
            continue;
        }

        for (pli next : graph[cur.second])
        {
            if ((isVisited[next.second] == false) || (dist[cur.second] + next.first < dist[next.second])) // 방문 안 했거나 현재 값이 더 낮은 경우
            {
                returnPath[next.second].clear();
                returnPath[next.second].push_back(cur.second);
                isVisited[next.second] = true;
                dist[next.second] = dist[cur.second] + next.first;
                pq.push({dist[next.second], next.second});
            }
            else if (dist[cur.second] + next.first == dist[next.second])
            {
                returnPath[next.second].push_back(cur.second);
            }
        }
    }
}
void findPath()
{
    queue<int> q;

    isVisited[B] = false;
    q.push(B);
    path.push_back(B);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : returnPath[cur])
        {
            if (isVisited[next] == true) // 재방문 안 했고 현재 값에서 다음 값의 차이가 통행하는데 걸리는 시간인 경우
            {
                isVisited[next] = false;
                path.push_back(next);
                q.push(next);
            }
        }
    }

    sort(path.begin(), path.end());
    cout << path.size() << "\n";
    for (int i : path)
    {
        cout << i << " ";
    }
}
int main()
{
    input();
    dijkstra();
    findPath();
    return 0;
}