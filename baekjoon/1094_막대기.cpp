#include <iostream>
using namespace std;

int X, cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> X;

    while (X)
    {
        cnt += X % 2;
        X /= 2;
    }

    cout << cnt;
}