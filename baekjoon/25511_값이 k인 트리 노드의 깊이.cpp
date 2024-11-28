#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int n, k;
vector<vector<int>> edges;
vector<int> vertexs;
queue<pii> q;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;

    vertexs = vector<int>(n);
    edges = vector<vector<int>>(n, vector<int>());

    for (int i = 1, p, c; i < n; ++i)
    {
        cin >> p >> c;
        edges[p].push_back(c);
    }

    for (int &vertex : vertexs)
    {
        cin >> vertex;
    }
}

void solve()
{
    q.push({0, 0});

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        if (vertexs[cur.second] == k)
        {
            cout << cur.first;
            break;
        }

        for (int next : edges[cur.second])
        {
            q.push({cur.first + 1, next});
        }
    }
}

int main()
{
    input();
    solve();
    return 0;
}