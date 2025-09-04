#include <iostream>
using namespace std;

int X, N, a, b;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> X >> N;

    while (N--)
    {
        cin >> a >> b;

        X -= a * b;
    }

    if (X == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}