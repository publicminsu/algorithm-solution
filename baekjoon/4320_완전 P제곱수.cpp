#include <iostream>
using namespace std;
using ll = long long;

ll x;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (cin >> x)
    {
        if (x == 0)
            break;

        int p = 1;

        if (x > 0)
        {
            for (ll i = 2; i * i <= x; ++i)
            {
                ll num = i;
                int exp = 1;

                while (num < x && exp < 32)
                {
                    num *= i;
                    ++exp;
                }

                if (num == x)
                {
                    p = max(p, exp);
                }
            }
        }
        else
        {
            for (ll i = 2; i * i <= llabs(x); ++i)
            {
                ll num = -i;
                int exp = 1;

                while (llabs(num) < llabs(x) && exp < 32)
                {
                    num *= -i;
                    ++exp;
                }

                if (num == x)
                {
                    p = max(p, exp);
                }
            }
        }

        cout << p << "\n";
    }
    return 0;
}
