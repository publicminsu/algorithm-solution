#include <iostream>
using namespace std;
int A, B, C, ABC;
int cnt[10];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> A >> B >> C;

    ABC = A * B * C;

    while (ABC)
    {
        ++cnt[ABC % 10];
        ABC /= 10;
    }

    for (int i = 0; i < 10; ++i)
    {
        cout << cnt[i] << "\n";
    }
    return 0;
}