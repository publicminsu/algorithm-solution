#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
void vInput(vector<ll> &v, int &size)
{
    v.push_back(0);
    for (int i = 1, j; i <= size; ++i)
    {
        cin >> j;
        v.push_back(j);
        v[i] += v[i - 1];
    }
}
void getSum(vector<ll> &v, vector<ll> &vSum)
{
    for (int i = 0; i < v.size(); ++i)
        for (int j = i + 1; j < v.size(); ++j)
            vSum.push_back(v[j] - v[i]);
    sort(vSum.begin(), vSum.end());
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    ll T, ret = 0;
    vector<ll> A, B, sumA, sumB;
    cin >> T >> n;
    vInput(A, n);
    cin >> m;
    vInput(B, m);
    getSum(A, sumA);
    getSum(B, sumB);
    for (ll i : sumA)
    {
        ll targetNum = T - i;
        int first = lower_bound(sumB.begin(), sumB.end(), targetNum) - sumB.begin();
        int last = upper_bound(sumB.begin(), sumB.end(), targetNum) - sumB.begin();
        ret += last - first;
    }
    cout << ret;
    return 0;
}