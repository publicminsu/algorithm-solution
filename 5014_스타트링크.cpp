#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int F, S, G, U, D;
    queue<int> bfs;
    cin >> F >> S >> G >> U >> D;
    vector<int> floors(F + 1);
    floors[S] = 1;
    bfs.push(S);
    while (!bfs.empty())
    {
        int cur = bfs.front();
        if (cur == G)
            break;
        bfs.pop();
        int up = cur + U, down = cur - D;
        if (up <= F && !floors[up])
        {
            floors[up] = floors[cur] + 1;
            bfs.push(up);
        }
        if (down >= 1 && !floors[down])
        {
            floors[down] = floors[cur] + 1;
            bfs.push(down);
        }
    }
    if (bfs.empty())
        cout << "use the stairs";
    else
        cout << floors[bfs.front()] - 1;
    return 0;
}