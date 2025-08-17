#include <iostream>
using namespace std;

using ll = long long;

ll N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    if (N == 1)
    {
        cout << 1;
    }
    else
    {
        for (ll i = 1, num = N; i <= N; ++i)
        {
            num -= i;

            if (num < 0)
            {
                cout << i - 1;
                break;
            }
        }
    }
    return 0;
}