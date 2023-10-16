#include <iostream>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
struct node
{
    int start, end, time;
};
vector<node> graph;
vector<ll> dist;
int N, M;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    dist = vector<ll>(N + 1, INF);
    graph = vector<node>(M);

    for (int i = 0, A, B, C; i < M; ++i)
    {
        cin >> A >> B >> C;
        graph[i] = {A, B, C};
    }
}
void bellmanFord()
{
    dist[1] = 0;

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            node n = graph[j];

            if (dist[n.start] != INF && dist[n.end] > dist[n.start] + n.time) // 시작 지점에 접근할 수 있고 값이 갱신될 수 있다면
            {
                dist[n.end] = dist[n.start] + n.time;
            }
        }
    }

    for (int j = 0; j < M; ++j)
    {
        node n = graph[j];

        if (dist[n.start] != INF && dist[n.end] > dist[n.start] + n.time) // 시작 지점에 접근할 수 있고 값이 갱신될 수 있다면
        {
            cout << -1;
            return;
        }
    }

    for (int i = 2; i <= N; ++i)
    {
        if (dist[i] == INF) // 도달할 수 없다면
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << dist[i] << "\n";
        }
    }
}
int main()
{
    input();
    bellmanFord();
    return 0;
}