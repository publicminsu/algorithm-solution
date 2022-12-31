#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int R, C, ret = 1001;
    cin >> R >> C;
    vector<vector<int>> map(R, vector<int>(C));
    queue<pair<int, int>> fBFS, jBFS, goal;

    for (int i = 0; i < R; ++i)
    {
        string col;
        cin >> col;
        for (int j = 0; j < C; ++j)
        {
            map[i][j] = col[j];
            switch (col[j])
            {
            case '.':
                map[i][j] = 0;
                break;
            case '#':
                map[i][j] = 1001;
                break;
            case 'F':
                map[i][j] = -1;
                fBFS.push({i, j});
                break;
            case 'J':
                if (i == R - 1 || j == C - 1 || i == 0 || j == 0)
                {
                    cout << 1;
                    exit(0);
                }
                map[i][j] = 1;
                jBFS.push({i, j});
                break;
            }
        }
    }
    while (!jBFS.empty())
    {
        auto jCur = jBFS.front();
        jBFS.pop();
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> jNext = {jCur.first + dy[i], jCur.second + dx[i]};
            if (jNext.first < 0 || jNext.second < 0 || jNext.first >= R || jNext.second >= C)
                continue;
            if (map[jNext.first][jNext.second] != 0)
                continue;
            if (jNext.first == R - 1 || jNext.second == C - 1 || jNext.first == 0 || jNext.second == 0)
            {
                goal.push(jNext);
            }
            map[jNext.first][jNext.second] = map[jCur.first][jCur.second] + 1;
            jBFS.push(jNext);
        }
    }
    while (!fBFS.empty())
    {
        auto fCur = fBFS.front();
        fBFS.pop();
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> fNext = {fCur.first + dy[i], fCur.second + dx[i]};
            if (fNext.first < 0 || fNext.second < 0 || fNext.first >= R || fNext.second >= C)
                continue;
            if (map[fNext.first][fNext.second] == 1001)
                continue;
            if (map[fNext.first][fNext.second] < abs(map[fCur.first][fCur.second] - 1))
                continue;
            map[fNext.first][fNext.second] = map[fCur.first][fCur.second] - 1;
            fBFS.push(fNext);
        }
    }
    while (!goal.empty())
    {
        auto cur = goal.front();
        goal.pop();
        if (map[cur.first][cur.second] > 0)
        {
            int number = map[cur.first][cur.second];
            if (ret > number)
                ret = number;
        }
    }
    if (ret == 1001)
        cout << "IMPOSSIBLE";
    else
        cout << ret;
    return 0;
}