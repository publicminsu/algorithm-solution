#include <iostream>
#include <string>
using namespace std;
int M, n;
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1}, d, x, y, cur;
string cmd;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> M >> n;
    x = y = cur = 0;
    while (n--)
    {
        cin >> cmd >> d;
        if (cmd == "MOVE")
        {
            x += dx[cur] * d;
            y += dy[cur] * d;
            if (x < 0 || y < 0 || x > M || y > M)
            {
                cout << -1;
                return 0;
            }
        }
        else
        {
            if (d == 0)
                --cur;
            else
                ++cur;
            cur = (cur + 4) % 4;
        }
    }
    cout << x << " " << y;
    return 0;
}