#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int H, W, cnt, time = 0;
    cin >> H >> W;
    vector<vector<bool>> map, visted;
    queue<pair<int, int>> bfs;
    set<pair<int, int>> cheese;
    for (int i = 0; i < H; ++i)
    {
        map.push_back(vector<bool>());
        for (int j = 0; j < W; ++j)
        {
            bool input;
            cin >> input;
            map[i].push_back(input);
        }
    }
    while (true)
    {
        cheese.clear();
        visted = vector<vector<bool>>(H, vector<bool>(W));
        bfs.push({0, 0});
        while (!bfs.empty())
        {
            pair<int, int> cur = bfs.front();
            bfs.pop();
            for (int i = 0; i < 4; ++i)
            {
                pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
                if (next.first < 0 || next.second < 0 || next.first >= H || next.second >= W || visted[next.first][next.second])
                    continue;
                visted[next.first][next.second] = true;
                if (map[next.first][next.second])
                    cheese.insert(next);
                else
                    bfs.push(next);
            }
        }
        if (!cheese.empty())
        {
            cnt = cheese.size();
            ++time;
        }
        else
            break;
        for (auto i : cheese)
        {
            map[i.first][i.second] = false;
        }
    }
    cout << time << "\n"
         << cnt;
    return 0;
}