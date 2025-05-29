#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141592653

int T, cmd;
double a, b;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;

    cout << fixed;
    cout.precision(8);

    while (T--)
    {
        cin >> cmd >> a >> b;

        if (cmd == 1)
        {
            double rad = atan2(b, a);

            if (rad < 0)
            {
                rad += 2 * PI;
            }

            cout << sqrt(a * a + b * b) << " " << rad;
        }
        else
        {
            cout << cos(b) * a << " " << sin(b) * a;
        }

        cout << "\n";
    }
    return 0;
}