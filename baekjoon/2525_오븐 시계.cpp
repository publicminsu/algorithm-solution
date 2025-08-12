#include <iostream>
using namespace std;
int A, B, C;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B >> C;
    int min = A * 60 + B + C;
    min %= 1440;

    cout << (min / 60) << " " << (min % 60);
    return 0;
}