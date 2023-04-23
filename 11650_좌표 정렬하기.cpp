#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<pii> v;
    for (int i = 0, x, y; i < N; ++i)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    for (pii p : v)
    {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}