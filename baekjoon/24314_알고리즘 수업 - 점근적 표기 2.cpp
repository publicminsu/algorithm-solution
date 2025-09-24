#include <iostream>
using namespace std;

int a1, a0, c, n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> a1 >> a0 >> c >> n;

    cout << (((a1 - c) * n + a0) >= 0 && (a1 >= c));
    return 0;
}