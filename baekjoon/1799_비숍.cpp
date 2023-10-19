#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> map;
vector<vector<bool>> isCross;
vector<vector<pii>> bishop;
int n;
void dfs(int len, int depth, vector<pii> &v, int &ret)
{
    ret = max(depth, ret);
    if (len == v.size())
        return;
    dfs(len + 1, depth, v, ret);

    int y = v[len].first, x = v[len].second;

    if (!map[y][x])
        return;

    int leftCross = x + y;
    if (isCross[0][leftCross])
        return;
    int rightCross = y - x + n;
    if (isCross[1][rightCross])
        return;
    isCross[0][leftCross] = isCross[1][rightCross] = true;
    dfs(len + 1, depth + 1, v, ret);
    isCross[0][leftCross] = isCross[1][rightCross] = false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    bishop = vector<vector<pii>>(2, vector<pii>());
    map = vector<vector<int>>(n, vector<int>(n));
    isCross = vector<vector<bool>>(2, vector<bool>(2 * n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j)
        {
            cin >> map[i][j];
            if ((i + j) % 2)
                bishop[1].push_back({i, j});
            else
                bishop[0].push_back({i, j});
        }
    int ret1 = 0, ret2 = 0;
    dfs(0, 0, bishop[0], ret1);
    dfs(0, 0, bishop[1], ret2);
    cout << ret1 + ret2;
    return 0;
}