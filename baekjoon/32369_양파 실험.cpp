#include <iostream>
using namespace std;
int N, A, B, a = 1, b = 1;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> A >> B;
    while (N--)
    {
        a += A;
        b += B;

        if (a < b)
        {
            swap(a, b);
        }
        else if (a == b)
        {
            --b;
        }
    }
    cout << a << " " << b;
    return 0;
}