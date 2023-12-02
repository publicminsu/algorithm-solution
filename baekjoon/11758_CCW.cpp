#include <iostream>
using namespace std;
struct point
{
    int x, y;
} p1, p2, p3;
int ccw(const point &a, const point &b, const point &c)
{
    int ret = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (ret < 0)
    {
        return -1;
    }
    else if (ret > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    cout << ccw(p1, p2, p3);
    return 0;
}