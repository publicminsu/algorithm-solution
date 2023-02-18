#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[] = {5, 3};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> suger(N + 1);
    queue<int> bfs;
    bfs.push(0);
    while (!bfs.empty())
    {
        int cur = bfs.front();
        bfs.pop();
        if (cur == N)
            break;
        for (int i = 0; i < 2; ++i)
        {
            int next = cur + dx[i];
            if (next > N || suger[next])
                continue;
            suger[next] = suger[cur] + 1;
            bfs.push(next);
        }
    }
    if (suger[N])
        cout << suger[N];
    else
        cout << -1;
    return 0;
}