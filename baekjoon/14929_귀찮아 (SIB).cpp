#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    ll sum = 0;
    vector<int> x;
    vector<ll> prefix;
    cin >> n;
    prefix.push_back(0);
    for (int i = 0, j; i < n; ++i)
    {
        cin >> j;
        x.push_back(j);
        prefix.push_back(prefix[i] + j);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        sum += (prefix[n] - prefix[i + 1]) * x[i];
    }
    cout << sum;
    return 0;
}