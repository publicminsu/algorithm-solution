#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> bfsQ;
int dist[501];
vector<int> graph[501];
int n, m, q;

void bfs()
{
    fill(dist + 1, dist + n + 1, -1);

    bfsQ.push(1);
    dist[1] = 0;

    while (!bfsQ.empty())
    {
        const int &curNode = bfsQ.front();
        bfsQ.pop();

        for (const int &nextNode : graph[curNode])
        {
            if (dist[nextNode] != -1)
            {
                continue;
            }

            dist[nextNode] = dist[curNode] + 1;
            bfsQ.push(nextNode);
        }
    }
}

void print()
{
    for (int i = 1; i <= n; ++i)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

void addEdge(const int &i, const int &j)
{
    graph[i].push_back(j);
    graph[j].push_back(i);
}

void removeEdge(const int &i, const int &j)
{
    graph[i].erase(find(graph[i].begin(), graph[i].end(), j));
    graph[j].erase(find(graph[j].begin(), graph[j].end(), i));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;

    while (m--)
    {
        int i, j;
        cin >> i >> j;
        addEdge(i, j);
    }

    cin >> q;

    while (q--)
    {
        int a, i, j;
        cin >> a >> i >> j;

        if (a == 1)
        {
            addEdge(i, j);
        }
        else
        {
            removeEdge(i, j);
        }

        bfs();
        print();
    }
    return 0;
}