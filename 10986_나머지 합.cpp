#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll N, M, ret = 0;
    cin >> N >> M;
    vector<ll> prefix, mod(M);
    int num;
    cin >> num;
    prefix.push_back(num);
    for (int i = 1; i < N; ++i)
    {
        cin >> num;
        prefix.push_back(prefix[i - 1] + num);
    }
    for (ll i : prefix)
    {
        int modNum = i % M;
        if (!modNum)
            ++ret;
        ++mod[modNum];
    }
    for (ll i : mod)
        if (i > 1)
            ret += i * (i - 1) / 2;
    cout << ret;
    return 0;
}