#include <iostream>
using namespace std;

using ll = long long;

int Q, cmd, x;
ll S, cur = 1, multi = 1, add;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> Q;

    while (Q--)
    {
        cin >> cmd;

        if (cmd != 3)
        {
            cin >> x;
        }

        switch (cmd)
        {
        case 0:
            add += x;
            break;
        case 1:
            multi *= x;
            add *= x;
            break;
        case 2:
            cur += x;
            break;
        case 3:
            cout << cur * multi + add << "\n";
            break;
        }
    }
    return 0;
}