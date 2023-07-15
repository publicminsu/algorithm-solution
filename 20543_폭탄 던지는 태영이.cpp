#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    vector<vector<ll>> map, ret;
    int N, M, gap;
    cin >> N >> M;
    map = ret = vector<vector<ll>>(N, vector<ll>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];
    gap = M / 2;
    for (int i = gap; i < N - gap; ++i)
        for (int j = gap; j < N - gap; ++j)
        {
            ll topSum = (i - gap - 1 < 0) ? 0 : map[i - gap - 1][j - gap];
            ll leftSum = (j - gap - 1 < 0) ? 0 : map[i - gap][j - gap - 1];
            ll topLeftSum = (i - gap - 1 < 0) || (j - gap - 1 < 0) ? 0 : map[i - gap - 1][j - gap - 1];
            ll topBoom = (i - M < 0) ? 0 : ret[i - M][j];
            ll leftBoom = (j - M < 0) ? 0 : ret[i][j - M];
            ll topLeftBoom = (i - M < 0) || (j - M < 0) ? 0 : ret[i - M][j - M];
            ret[i][j] = map[i - gap][j - gap] - topSum - leftSum + topLeftSum + topBoom + leftBoom - topLeftBoom;
        }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << ret[i][j] * -1 << " ";
        cout << "\n";
    }
    return 0;
}