#include <iostream>
#include <unordered_set>
using namespace std;

using ll = long long;

unordered_set<ll> us;
ll N, M;

bool canMakeHeart(ll n)
{
    if (us.find(n) != us.end())
    {
        return false;
    }

    us.insert(n);

    if (n == M)
    {
        return true;
    }

    if (n == 1)
    {
        return false;
    }

    ll half = n / 2;
    bool evenValue = canMakeHeart(half);

    if (n % 2)
    {
        return evenValue || canMakeHeart(half + 1);
    }

    return evenValue;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    cout << (canMakeHeart(N) ? "YES" : "NO");

    return 0;
}