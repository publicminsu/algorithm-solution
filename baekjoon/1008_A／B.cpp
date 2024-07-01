#include <iostream>
using namespace std;
double A, B;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed;
    cout.precision(10);

    cin >> A >> B;
    cout << (A / B);
    return 0;
}