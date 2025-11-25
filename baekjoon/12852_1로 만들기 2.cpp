#include <iostream>
#include <queue>
using namespace std;

int N;
int parents[1000001];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
}

void push(queue<int> &q, int node, int parent)
{
    if (parents[node])
    {
        return;
    }

    q.push(node);
    parents[node] = parent;
}

void bfs()
{
    queue<int> q;
    q.push(N);

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();

        if (curNode == 1)
        {
            break;
        }

        if (curNode % 3 == 0)
        {
            push(q, curNode / 3, curNode);
        }

        if (curNode % 2 == 0)
        {
            push(q, curNode / 2, curNode);
        }

        push(q, curNode - 1, curNode);
    }
}

void recurPrint(int node, int cnt)
{
    if (!parents[node])
    {
        cout << cnt << "\n"
             << node;
        return;
    }

    int parentNode = parents[node];

    recurPrint(parentNode, cnt + 1);

    cout << " " << node;
}

int main()
{
    input();
    bfs();
    recurPrint(1, 0);
    return 0;
}