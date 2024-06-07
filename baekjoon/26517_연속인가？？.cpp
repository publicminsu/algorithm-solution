#include <iostream>
using namespace std;
using ll = long long;
ll k, a, b, c, d;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> k >> a >> b >> c >> d;
    ll kab = k * a + b;
    ll kcd = k * c + d;
    if (kab == kcd)
    {
        cout << "Yes " << kab;
    }
    else
    {
        cout << "No";
    }
    return 0;
}