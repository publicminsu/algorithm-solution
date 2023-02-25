#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> map, melt;
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
int N, M;
int melting()
{
    int ice = 0;
    fill(melt.begin(), melt.end(), vector<int>(M));
    // melt = vector<vector<int>>(N, vector<int>(M)); // 얼마나 녹은지 확인
    for (int i = 1; i < N - 1; ++i)
        for (int j = 1; j < M - 1; ++j)
            if (map[i][j])
            {
                ++ice;
                for (int k = 0; k < 4; ++k)
                {
                    int y = i + dy[k], x = j + dx[k];
                    if (!map[y][x])
                        ++melt[i][j];
                }
            }
    for (int i = 1; i < N - 1; ++i)
        for (int j = 1; j < M - 1; ++j)
        {
            map[i][j] -= melt[i][j];
            if (map[i][j] < 0)
                map[i][j] = 0;
        }
    return ice;
}
bool isPart()
{
    fill(melt.begin(), melt.end(), vector<int>(M)); // visted로 재활용
    bool once = false;
    for (int i = 1; i < N - 1; ++i)
        for (int j = 1; j < M - 1; ++j)
        {
            if (melt[i][j] || !map[i][j])
                continue;
            if (once)
                return once;
            once = true;
            queue<pair<int, int>> bfs;
            bfs.push({i, j});
            melt[i][j] = true;
            while (!bfs.empty())
            {
                pair<int, int> cur = bfs.front();
                bfs.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int y = cur.first + dy[k], x = cur.second + dx[k];
                    if (!melt[y][x] && map[y][x])
                    {
                        melt[y][x] = true;
                        bfs.push({y, x});
                    }
                }
            }
        }
    return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    map = melt = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
        }
    int day = 1;
    while (true)
    {
        int ice = melting();
        if (!ice)
        {
            cout << 0;
            break;
        }
        if (isPart())
        {
            cout << day;
            break;
        }
        else
            ++day;
    }
    return 0;
}