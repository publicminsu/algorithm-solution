#include <iostream>
using namespace std;
int xs, ys, xe, ye, dx, dy, ax, ay, dist = 1000000;
int gcd(int a, int b)
{
    if (!a || !b)
    {
        return 0;
    }

    if (a < b)
    {
        swap(a, b);
    }

    while (a % b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return b;
}
int main()
{
    cin >> xs >> ys >> xe >> ye >> dx >> dy;

    int d = abs(gcd(dx, dy));

    if (dx || dy)
    {
        if (!dy)
        {
            dx = 1;
        }
        else if (!dx)
        {
            dy = 1;
        }
        else
        {
            dy /= d;
            dx /= d;
        }
    }
    else if (!dx && !dy)
    {
        cout << xe << " " << ye;
        return 0;
    }

    while (xe <= 100 && ye <= 100 && xe >= -100 && ye >= -100)
    {
        int nextDist = (xs - xe) * (xs - xe) + (ys - ye) * (ys - ye);

        if (nextDist < dist)
        {
            dist = nextDist;
            ax = xe;
            ay = ye;
        }

        xe += dx;
        ye += dy;
    }

    cout << ax << " " << ay;
    return 0;
}