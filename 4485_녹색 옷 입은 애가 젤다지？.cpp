#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, pair<int, int>> pii;
int N, map[125][125], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
bool visted[125][125];
bool input()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
            visted[i][j] = false;
        }
    return N;
}
int solve()
{
    visted[0][0] = true;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({map[0][0], {0, 0}});
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        int val = cur.first, y = cur.second.first, x = cur.second.second;
        if (y == N - 1 && x == N - 1)
            return val;
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N || visted[ny][nx])
                continue;
            visted[ny][nx] = true;
            pq.push({val + map[ny][nx], {ny, nx}});
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int tc = 1;
    while (input())
        cout << "Problem " << tc++ << ": " << solve() << "\n";
    return 0;
}