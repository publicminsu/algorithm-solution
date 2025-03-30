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
        if (N % 2)
        {
            cout << 0;
        }
        else
        {
            N /= 2;
            cout << (1LL << N);
        }
        cout << "\n";
    }
}