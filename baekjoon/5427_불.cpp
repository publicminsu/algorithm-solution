#include <iostream>
#include <queue>
#include <string>
#include <climits>
using namespace std;
int map[1001][1001];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    queue<pair<int, int>> fire, human, goal;
    while (T--)
    {
        fire = human = goal = queue<pair<int, int>>();
        int w, h, ret = INT_MAX;
        cin >> w >> h;
        for (int i = 0; i < h; ++i)
        {
            string k;
            cin >> k;
            for (int j = 0; j < w; ++j)
            {
                if (k[j] == '#')
                    map[i][j] = INT_MAX;
                else if (k[j] == '.')
                    map[i][j] = 0;
                else if (k[j] == '*')
                {
                    map[i][j] = -1;
                    fire.push({i, j});
                }
                else
                {
                    if (i == 0 || j == 0 || i == h - 1 || j == w - 1)
                        ret = 1;
                    map[i][j] = 1;
                    human.push({i, j});
                }
            }
        }
        if (ret == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        while (!human.empty())
        {
            auto cur = human.front();
            human.pop();
            for (int i = 0; i < 4; ++i)
            {
                pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
                if (next.first < 0 || next.second < 0 || next.first >= h || next.second >= w)
                    continue;
                if (map[next.first][next.second])
                    continue;
                if (next.first == 0 || next.second == 0 || next.first == h - 1 || next.second == w - 1)
                    goal.push(next);
                map[next.first][next.second] = map[cur.first][cur.second] + 1;
                human.push(next);
            }
        }
        while (!fire.empty())
        {
            auto cur = fire.front();
            fire.pop();
            for (int i = 0; i < 4; ++i)
            {
                pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
                if (next.first < 0 || next.second < 0 || next.first >= h || next.second >= w)
                    continue;
                if (map[next.first][next.second] == INT_MAX)
                    continue;
                if (map[next.first][next.second] < abs(map[cur.first][cur.second] - 1))
                    continue;
                map[next.first][next.second] = map[cur.first][cur.second] - 1;
                fire.push(next);
            }
        }
        while (!goal.empty())
        {
            auto cur = goal.front();
            goal.pop();
            int number = map[cur.first][cur.second];
            if (number > 0)
            {
                if (ret > number)
                    ret = number;
            }
        }
        if (ret == INT_MAX)
            cout << "IMPOSSIBLE";
        else
            cout << ret;
        cout << "\n";
    }
    return 0;
}