#include <iostream>

using namespace std;

int T, N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        cin >> N;

        cout << "Case #" << i << ": ";

        if (N > 4500)
        {
            cout << "Round 1";
        }
        else if (N > 1000)
        {
            cout << "Round 2";
        }
        else if (N > 25)
        {
            cout << "Round 3";
        }
        else
        {
            cout << "World Finals";
        }

        cout << "\n";
    }
    return 0;
}