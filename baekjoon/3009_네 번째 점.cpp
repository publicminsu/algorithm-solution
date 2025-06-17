#include <iostream>
#include <algorithm>
using namespace std;

int x[3], y[3];

int main()
{
    for (int i = 0; i < 3; ++i)
    {
        cin >> x[i] >> y[i];
    }

    sort(x, x + 3);
    sort(y, y + 3);

    int nX = x[1] == x[0] ? x[2] : x[0];
    int nY = y[1] == y[0] ? y[2] : y[0];

    cout << nX << " " << nY;
    return 0;
}