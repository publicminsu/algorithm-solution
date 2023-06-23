#include <iostream>
#include <cmath>
using namespace std;
void point(int _x1, int _y1, int _r1, int _x2, int _y2, int _r2);
int main()
{
    int i;
    cin >> i;
    while (i > 0)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        point(x1, y1, r1, x2, y2, r2);
        i--;
    }
    return 0;
}
void point(int _x1, int _y1, int _r1, int _x2, int _y2, int _r2)
{
    int rangePow = pow((_x2 - _x1), 2) + pow((_y2 - _y1), 2);
    if (_r1 == 0)
        cout << 1;
    else if (rangePow == 0 && _r1 == _r2)
        cout << -1;
    else if (rangePow > pow(_r1 + _r2, 2))
        cout << 0;
    else if (rangePow < pow(_r2 - _r1, 2))
        cout << 0;
    else if (rangePow == pow(_r2 - _r1, 2))
        cout << 1;
    else if (rangePow == pow(_r1 + _r2, 2))
        cout << 1;
    else
        cout << 2;
    cout << endl;
    return;
}