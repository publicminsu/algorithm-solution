#include <iostream>
#include <vector>
using namespace std;
vector<int> d, w;
int N, ret = 0;
void dfs(int curI, int cnt)
{
    ret = cnt > ret ? cnt : ret;
    if (curI == N)
        return;
    if (d[curI] <= 0)
    {
        dfs(curI + 1, cnt);
        return;
    }
    for (int i = 0; i < N; ++i)
    {
        if (d[i] <= 0 || curI == i)
            continue;
        d[i] -= w[curI];
        d[curI] -= w[i];
        dfs(curI + 1, cnt + (d[i] > 0 ? 0 : 1) + (d[curI] > 0 ? 0 : 1));
        d[i] += w[curI];
        d[curI] += w[i];
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    d = w = vector<int>(N);
    for (int i = 0; i < N; ++i)
        cin >> d[i] >> w[i];
    dfs(0, 0);
    cout << ret;
    return 0;
}