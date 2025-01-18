#include <iostream>
#include <set>
using namespace std;
using pii = pair<int, int>;
set<pii> v;
int S;

void push(int diff, int div, int value)
{
    if (value % div == 0)
    {
        value /= div;
        if (value >= 0 && value <= 200)
        {
            v.insert({diff, value});
        }
    }
}

void push(int diff, int mul)
{
    int value = S - diff * mul;

    push(diff, 212, value);
    push(diff, 305, value);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> S;

    if (S % 4763)
    {
        cout << "0";
        return 0;
    }

    S /= 4763;

    for (int i = 0; i <= 200; ++i)
    {
        push(i, 508);
        push(i, 108);
    }

    cout << v.size() << "\n";

    for (pii p : v)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}