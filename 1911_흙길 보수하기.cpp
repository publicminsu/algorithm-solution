#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, L, ret = 0, start = 0;
    cin >> N >> L;
    vector<pair<int, int>> v;
    while (N--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        v.push_back({n1, n2});
    }
    sort(v.begin(), v.end());
    for (auto p : v)
    {
        start = max(start, p.first);
        int multi = (p.second - start + L - 1) / L;
        ret += multi;
        start += multi * L;
    }
    cout << ret;
    return 0;
}