#include <iostream>
using namespace std;
int n, fib1, fib2;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    fib1 = 1;
    fib2 = 1;
    for (int i = 3; i <= n; ++i)
    {
        int sum = fib1 + fib2;
        fib1 = fib2;
        fib2 = sum;
    }
    cout << fib2 << " " << n - 2;
    return 0;
}