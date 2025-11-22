#include <iostream>

using namespace std;
using ll = long long;

int nums[2], dens[2];

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 2; ++i)
    {
        cin >> nums[i] >> dens[i];
    }
}

void solve()
{
    int num = nums[0] * dens[1] + nums[1] * dens[0];
    int den = dens[0] * dens[1];

    int div = gcd(num, den);

    cout << num / div << " " << den / div;
}

int main()
{
    input();
    solve();
    return 0;
}