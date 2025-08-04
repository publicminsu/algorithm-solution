#include <iostream>
using namespace std;
string A, B;
long long result;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> A >> B;

    for (const char &c1 : A)
    {
        long long n1 = c1 - '0';

        for (const char &c2 : B)
        {
            long long n2 = c2 - '0';

            result += n1 * n2;
        }
    }

    cout << result;
    return 0;
}