#include <iostream>
using namespace std;
int T, N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        if (N == 1)
        {
            cout << 0;
        }
        else
        {
            cout << "1";
            for (int i = 0; i < N - 2; ++i)
            {
                cout << "2";
            }
            cout << "1";
        }
        cout << "\n";
    }
    return 0;
}