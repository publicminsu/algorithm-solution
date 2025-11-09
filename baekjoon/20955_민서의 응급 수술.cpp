#include <iostream>

using namespace std;

int N, M, cnt;
int parent[100001];

int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }

    return parent[x] = find(parent[x]);
}

bool merge(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
    {
        return false;
    }

    parent[x] = y;
    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        parent[i] = i;
    }

    while (M--)
    {
        int u, v;
        cin >> u >> v;

        if (!merge(u, v))
        {
            ++cnt;
        }
    }

    for (int i = 2; i <= N; ++i)
    {
        if (merge(1, i))
        {
            ++cnt;
        }
    }

    cout << cnt;

    return 0;
}
