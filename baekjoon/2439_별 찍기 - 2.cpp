#include <iostream>
using namespace std;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = N - i - 1; j > 0; --j)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; ++j)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}