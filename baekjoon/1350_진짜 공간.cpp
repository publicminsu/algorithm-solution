#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int N, fileSize;
ll cnt;
vector<ll> v;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    v = vector<ll>(N);
    for (ll &i : v)
    {
        cin >> i;
    }
    cin >> fileSize;

    for (const ll &i : v)
    {
        cnt += i / fileSize + (i % fileSize != 0);
    }

    cout << fileSize * cnt;
    return 0;
}