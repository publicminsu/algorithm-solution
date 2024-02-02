#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> guns;
int M, N, L, answer;
void init()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> M >> N >> L;
    guns = vector<int>(M);
    for (int &gun : guns)
    {
        cin >> gun;
    }

    sort(guns.begin(), guns.end());
}
void solve()
{
    int y, x;
    while (N--)
    {
        cin >> x >> y;
        if (y > L) // y가 L보다 크다면
        {
            continue;
        }

        int gap = L - y;
        auto lb = lower_bound(guns.begin(), guns.end(), x - gap);
        auto ub = upper_bound(guns.begin(), guns.end(), x + gap);

        if (ub - lb > 0) // 값이 존재한다면
        {
            ++answer;
        }
    }
    cout << answer;
}
int main()
{
    init();
    solve();
    return 0;
}