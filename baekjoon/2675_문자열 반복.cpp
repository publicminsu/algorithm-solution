#include <iostream>
using namespace std;
int T, R;
string S;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> R >> S;

        for (const char &c : S)
        {
            for (int i = 0; i < R; ++i)
            {
                cout << c;
            }
        }

        cout << "\n";
    }
    return 0;
}