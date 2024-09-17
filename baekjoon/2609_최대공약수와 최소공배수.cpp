#include <iostream>
using namespace std;
int A, B, C;
int gcd(int x, int y)
{
    if (!y)
    {
        return x;
    }
    return gcd(y, x % y);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> A >> B;

    C = gcd(A, B);

    cout << C << "\n"
         << A * B / C;
    return 0;
}