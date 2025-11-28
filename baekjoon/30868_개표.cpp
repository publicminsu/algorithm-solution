#include <iostream>

using namespace std;

int T, n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> n;

        for (int i = 0; i < n / 5; ++i)
        {
            cout << "++++ ";
        }

        for (int i = 0; i < n % 5; ++i)
        {
            cout << "|";
        }

        cout << "\n";
    }
    return 0;
}