#include <iostream>
using namespace std;

int T, A, B;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        cin >> A >> B;

        cout << "Case #" << i << ": " << A << " + " << B << " = " << A + B << "\n";
    }
    return 0;
}