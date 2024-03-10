#include <iostream>
#include <cmath>
using namespace std;
double a, b, h, lowH;
const double PI = acos(-1);
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed;
    cout.precision(7);

    cin >> a >> b >> h;

    if (a == b) // 원기둥인 경우
    {
        cout << -1;
        return 0;
    }

    if (a > b)
    {
        swap(a, b);
    }

    lowH = a * h / (b - a);

    double bigSize = pow(lowH + h, 2) + pow(b, 2);
    double smallSize = a ? pow(lowH, 2) + pow(a, 2) : 0;

    cout << (bigSize - smallSize) * PI;
    return 0;
}