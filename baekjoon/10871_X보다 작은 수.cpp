#include <iostream>
using namespace std;
int N, X, A;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> X;
    while (N--)
    {
        cin >> A;

        if (A < X)
        {
            cout << A << " ";
        }
    }
    return 0;
}