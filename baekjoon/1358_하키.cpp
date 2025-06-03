#include <iostream>

using namespace std;

int W, H, X, Y, P, radius, cnt;

bool isInsideCircle(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2;
    int dy = y1 - y2;

    return (dx * dx + dy * dy) <= (radius * radius);
}

bool isInsideBox(int x, int y)
{
    return x >= X && x <= X + W && y >= Y && y <= Y + H;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> W >> H >> X >> Y >> P;
    radius = H / 2;

    while (P--)
    {
        int x, y;
        cin >> x >> y;

        bool isInsideRink = isInsideCircle(x, y, X, Y + radius) || isInsideCircle(x, y, X + W, Y + radius) || isInsideBox(x, y);
        cnt += isInsideRink;
    }

    cout << cnt;
    return 0;
}