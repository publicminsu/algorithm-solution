#include <iostream>
using namespace std;
int N, A, B;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        A += j;
    }

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        B += j;
    }

    cout << B << " " << A;
    return 0;
}