#include <iostream>
using namespace std;

int A, B, C;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> A >> B >> C;

    C %= 2;

    if (C)
    {
        A ^= B;
    }

    cout << A;
}