#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n, sum = 0, ret;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    if (!n)
    {
        cout << 0;
        return 0;
    }
    v = vector<int>(n);
    int out = round(n * 0.15f);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = out; i < n - out; ++i)
        sum += v[i];
    ret = round((float)sum / (n - 2 * out));
    cout << ret;
    return 0;
}