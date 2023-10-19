#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
vector<vector<bool>> graph, isVisted;
int W, H, ret = 0;
pii even[] = {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 0}}, odd[] = {{-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};
queue<pii> q;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> W >> H;
    graph = isVisted = vector<vector<bool>>(H + 2, vector<bool>(W + 2));
    for (int i = 1; i <= H; ++i)
        for (int j = 1, k; j <= W; ++j)
            cin >> k, graph[i][j] = k;
    q.push({0, 0});
    isVisted[0][0] = true;
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        pii *temp = ((cur.first % 2) ? odd : even);
        for (int k = 0; k < 6; ++k)
        {
            int ny = cur.first + temp[k].first, nx = cur.second + temp[k].second;
            if (ny < 0 || nx < 0 || ny > H + 1 || nx > W + 1 || isVisted[ny][nx])
                continue;
            if (graph[ny][nx])
            {
                ++ret;
                continue;
            }
            isVisted[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    cout << ret;
    return 0;
}