#include <iostream>
using namespace std;

int N, X, Y, Z;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> X >> Y >> Z;

        cout << (!((X + Y + Z) % 2) ? "YES" : "NO") << "\n";
    }
    return 0;
}