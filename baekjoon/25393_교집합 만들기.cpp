#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int leftToRight[1000001], rightToLeft[1000001];
set<pair<int, int>> s;
int N, Q, l, r;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    memset(rightToLeft, 0x3f, sizeof(rightToLeft));

    cin >> N;

    while (N--)
    {
        cin >> l >> r;

        leftToRight[l] = max(leftToRight[l], r);
        rightToLeft[r] = min(rightToLeft[r], l);

        s.insert({l, r});
    }

    cin >> Q;

    while (Q--)
    {
        cin >> l >> r;

        if (s.find({l, r}) != s.end())
        {
            cout << 1;
        }
        else if (leftToRight[l] >= r && rightToLeft[r] <= l)
        {
            cout << 2;
        }
        else
        {
            cout << -1;
        }

        cout << "\n";
    }
    return 0;
}