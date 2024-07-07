#include <iostream>
using namespace std;
int a, b, c;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        cin >> a >> b >> c;

        if (a == 0)
        {
            break;
        }

        if (c < a)
        {
            swap(c, a);
        }

        if (c < b)
        {
            swap(c, b);
        }

        cout << (c * c == a * a + b * b ? "right" : "wrong") << "\n";
    }

    return 0;
}