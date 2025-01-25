#include <iostream>
using namespace std;

using ll = long long;

struct pos
{
    ll y, x;

    pos operator-(const pos other)
    {
        return {y - other.y, x - other.x};
    }
};

int ccw(pos p1, pos p2, pos p3)
{
    pos v1 = p1 - p2;
    pos v2 = p1 - p3;

    ll value = v1.x * v2.y - v1.y * v2.x;

    if (value < 0)
    {
        return -1;
    }

    return value != 0;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    pos p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    cout << (ccw(p1, p2, p3) * ccw(p1, p2, p4) < 0 &&
             ccw(p3, p4, p1) * ccw(p3, p4, p2) < 0);
    return 0;
}