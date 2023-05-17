#include <iostream>
#include <vector>
using namespace std;
int shape[4][2] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
int N, M, ret = 0;
vector<vector<int>> map;
vector<vector<bool>> visted;
vector<pair<int, int>> pos;
bool isPossible(int y, int x, int angle)
{
    for (int i = 0; i < 4; ++i)
    {
        if (i == angle)
            continue;
        if (visted[y + shape[i][0]][x + shape[i][1]])
            return false;
    }
    return true;
}
int build(int y, int x, int angle, bool b)
{
    int sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (i == angle)
            continue;
        visted[y + shape[i][0]][x + shape[i][1]] = b;
        sum += map[y + shape[i][0]][x + shape[i][1]];
    }
    angle = (angle + 2) % 4;
    sum += map[y + shape[angle][0]][x + shape[angle][1]];
    return sum;
}
void dfs(int idx, int sum)
{
    for (int i = idx; i < pos.size(); ++i)
    {
        int y = pos[i].first, x = pos[i].second;
        for (int j = 0; j < 4; ++j)
        {
            if (!isPossible(y, x, j))
                continue;
            dfs(i + 1, sum + build(y, x, j, true));
            build(y, x, j, false);
        }
    }
    ret = sum > ret ? sum : ret;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    map = vector<vector<int>>(N, vector<int>(M));
    visted = vector<vector<bool>>(N, vector<bool>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
            if (i < N - 1 && j < M - 1)
                pos.push_back({i, j});
        }
    dfs(0, 0);
    cout << ret;
    return 0;
}