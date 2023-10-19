#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
vector<vector<ll>> abcd;
vector<ll> ab, cd;
int n;
ll ret = 0;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    abcd = vector<vector<ll>>(n, vector<ll>(4));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> abcd[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            ab.push_back(abcd[i][0] + abcd[j][1]);
            cd.push_back(-(abcd[i][2] + abcd[j][3]));
        }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    for (int i = 0; i < ab.size(); ++i)
    {
        ll num = ab[i];
        auto cdLb = lower_bound(cd.begin(), cd.end(), num);
        if (*cdLb != num)
            continue;
        auto abUb = upper_bound(ab.begin(), ab.end(), num);
        ll abLen = abUb - ab.begin();
        auto cdUb = upper_bound(cd.begin(), cd.end(), num);
        ret += (cdUb - cdLb) * (abLen - i);
        i = abLen - 1;
    }
    cout << ret;
    return 0;
}