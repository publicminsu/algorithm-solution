#include <iostream>
using namespace std;
int A, B;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> A >> B)
    {
        if (!A && !B)
        {
            break;
        }

        cout << A + B << "\n";
    }
    return 0;
}