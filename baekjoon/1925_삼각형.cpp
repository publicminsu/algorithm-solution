#include <iostream>
using namespace std;
int x[3], y[3];

int calcDx(int i, int j)
{
    return x[i] - x[j];
}

int calcDy(int i, int j)
{
    return y[i] - y[j];
}

int calcLengthSqr(int i, int j)
{
    double dx = calcDx(i, j);
    double dy = calcDy(i, j);

    return dx * dx + dy * dy;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 3; ++i)
    {
        cin >> x[i] >> y[i];
    }

    if (calcDx(0, 1) * calcDy(1, 2) == calcDx(1, 2) * calcDy(0, 1))
    {
        cout << "X";
    }
    else
    {
        double lengthSqr01 = calcLengthSqr(0, 1);
        double lengthSqr12 = calcLengthSqr(1, 2);
        double lengthSqr20 = calcLengthSqr(2, 0);

        bool sameLength012 = lengthSqr01 == lengthSqr12;
        bool sameLength120 = lengthSqr12 == lengthSqr20;
        bool sameLength201 = lengthSqr20 == lengthSqr01;

        if (sameLength012 && sameLength120 && sameLength201)
        {
            cout << "Triangle";
        }
        else
        {
            if (lengthSqr01 == lengthSqr12 + lengthSqr20 || lengthSqr12 == lengthSqr01 + lengthSqr20 || lengthSqr20 == lengthSqr01 + lengthSqr12)
            {
                cout << "Jikkak";
            }
            else
            {
                if (lengthSqr01 > lengthSqr12 + lengthSqr20 || lengthSqr12 > lengthSqr01 + lengthSqr20 || lengthSqr20 > lengthSqr01 + lengthSqr12)
                {
                    cout << "Dunkak";
                }
                else
                {
                    cout << "Yeahkak";
                }
            }

            if (sameLength012 || sameLength120 || sameLength201)
            {
                cout << "2";
            }
        }

        cout << "Triangle";
    }

    return 0;
}
