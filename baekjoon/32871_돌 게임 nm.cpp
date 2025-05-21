#include <iostream>
using namespace std;

int T;
long long n, m;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> n >> m;

        if (n == 1 || m == 1)
        {
            cout << "YES";
        }
        else
        {
            cout << ((n + m) % 2 == 1 ? "YES" : "NO");
        }

        cout << "\n";
    }
    return 0;
}