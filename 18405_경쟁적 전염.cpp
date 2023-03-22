#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, K, S, X, Y;
    cin >> N >> K;

    vector<vector<int>> map(N, vector<int>(N));
    vector<pair<int, pair<int, int>>> v;
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            int k;
            cin >> k;
            if (k)
            {
                v.push_back({k, {i, j}});
                map[i][j] = k;
            }
        }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        q.push({0, i.second});
    }
    cin >> S >> X >> Y;
    --X, --Y;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (cur.first == S)
            break;
        for (int j = 0; j < 4; ++j)
        {
            pair<int, int> nextPos = {cur.second.first + dy[j], cur.second.second + dx[j]};
            if (nextPos.first < 0 || nextPos.second < 0 || nextPos.first >= N || nextPos.second >= N || map[nextPos.first][nextPos.second])
                continue;
            if (X == nextPos.first && Y == nextPos.second)
            {
                cout << map[cur.second.first][cur.second.second];
                return 0;
            }
            q.push({cur.first + 1, nextPos});
            map[nextPos.first][nextPos.second] = map[cur.second.first][cur.second.second];
        }
    }
    cout << map[X][Y];
    return 0;
}