#include <iostream>
using namespace std;
double a1, a0, c, n;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> a1 >> a0 >> c >> n;

    cout << ((a0 / (c - a1) <= n) && (a1 <= c));
    return 0;
}