#include <iostream>
#include <vector>
using namespace std;
vector<bool> isVisited;
int N, Q, x, parent, visitedParent;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    isVisited = vector<bool>(N + 1);
    while (Q--)
    {
        cin >> x;
        parent = x;
        visitedParent = N + 1;
        while (parent)
        {
            if (isVisited[parent])
                visitedParent = parent;
            parent >>= 1;
        }
        if (visitedParent == N + 1)
        {
            isVisited[x] = true;
            cout << 0;
        }
        else
        {
            cout << visitedParent;
        }
        cout << "\n";
    }
    return 0;
}