#include <iostream>
using namespace std;
using ll = long long;
int n;
int fib1(int n)
{
    ll n1 = 1;
    ll n2 = 1;
    ll sum;
    for (int i = 3; i <= n; ++i)
    {
        sum = (n1 + n2) % 1000000007;
        n1 = n2;
        n2 = sum;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    cout << fib1(n) << " " << n - 2;

    return 0;
}