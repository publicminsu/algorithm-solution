#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
int G, P, g, cnt;
int find(int cur)
{
    if (parent[cur])
        return parent[cur] = find(parent[cur] - 1);
    else
    {
        if (cur == 0)
            return 0;
        return parent[cur] = cur;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> G >> P;
    parent = vector<int>(G + 1);
    while (P--)
    {
        cin >> g;
        if (find(g))
            ++cnt;
        else
            break;
    }
    cout << cnt;
    return 0;
}