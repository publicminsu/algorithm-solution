#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, x1, x2, y1, y2;
    cin >> N >> M;
    vector<vector<int>> map(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            cin >> map[i][j];
            if (j != 1)
                map[i][j] += map[i][j - 1];
        }
    for (int i = 2; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            map[i][j] += map[i - 1][j];
    while (M--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << map[x2][y2] - (map[x1 - 1][y2] + map[x2][y1 - 1]) + map[x1 - 1][y1 - 1] << "\n";
    }
    return 0;
}