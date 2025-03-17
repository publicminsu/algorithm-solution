#include <iostream>
using namespace std;
long long N;
int R, C;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> R >> C;

    if (N == 3)
    {
        if (R == 2 && C == 2)
        {
            cout << 1;
        }
        else
        {
            cout << 4;
        }
    }
    else
    {
        if (N % 2)
        {
            if ((R + C) % 2)
            {
                cout << (N * N) / 2;
            }
            else
            {
                cout << (N * N) / 2 + 1;
            }
        }
        else
        {
            cout << (N * N) / 2;
        }
    }
}