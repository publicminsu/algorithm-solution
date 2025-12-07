#include <iostream>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    if (N < 10)
    {
        cout << N;
    }
    else
    {
        int digits = 0;

        for (int i = 1; i <= N; i *= 10)
        {
            digits += N - i + 1;
        }

        cout << digits;
    }
    return 0;
}