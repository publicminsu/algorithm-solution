#include <iostream>
#include <vector>
using namespace std;
struct part
{
    int p[3];
};
vector<part> v;
int a, b, c, N;
vector<int> normal;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b >> c >> N;
    normal = vector<int>(a + b + c + 1, 2);
    for (int x = 0, i, j, k, r; x < N; ++x)
    {
        cin >> i >> j >> k >> r;
        if (r)
        {
            normal[i] = normal[j] = normal[k] = true;
            continue;
        }
        v.push_back({i, j, k});
    }
    for (part p : v)
    {
        int prev = -1, cnt = 0;
        for (int i : p.p)
            if (normal[i] != 1)
            {
                prev = i;
                ++cnt;
            }
        if (cnt == 1)
            normal[prev] = 0;
    }
    for (int i = 1; i <= a + b + c; ++i)
        cout << normal[i] << "\n";
    return 0;
}