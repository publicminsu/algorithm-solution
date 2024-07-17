#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int N, Q;
ll my, sumOther, maxOther;
vector<ll> count;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> Q;

    count = vector<ll>(N + 1);

    while (Q--)
    {
        ll cmd, x, y;

        cin >> cmd >> x >> y;

        if (cmd == 1)
        {
            if (y == N + 1)
            {
                my += x;
            }
            else
            {
                sumOther += x;

                count[y] += x;
                maxOther = max(count[y], maxOther);
            }
        }
        else
        {
            cout << ((my + x > maxOther && (my + x - 1) * N >= sumOther + y) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}