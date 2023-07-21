#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(n, 10000000));
    for (int i = 0; i < n; ++i)
        map[i][i] = 0;

    while (m--)
    {
        cin >> a >> b >> c;
        --a, --b;
        map[a][b] = min(map[a][b], c);
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                map[i][j] = min(map[i][k] + map[k][j], map[i][j]);
            }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (map[i][j] == 10000000)
                map[i][j] = 0;
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}