#include <iostream>
using namespace std;
typedef unsigned long long ull;
bool isPrime(ull num)
{
    for (ull i = 2; i * i <= num; ++i)
    {
        if (!(num % i))
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int tc;
    ull n;
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        if (n == 0 || n == 1)
            n = 2;
        while (!isPrime(n))
        {
            ++n;
        }
        cout << n << "\n";
    }
    return 0;
}