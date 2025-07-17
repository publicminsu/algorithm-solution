#include <iostream>
using namespace std;

int N, F;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> F;

    N /= 100;
    N *= 100;

    for (int i = 0; i < 100; ++i)
    {
        if ((N + i) % F)
        {
            continue;
        }

        int result = (N + i) % 100;

        if (result < 10)
        {
            cout << 0 << result;
        }
        else
        {
            cout << result;
        }

        break;
    }

    return 0;
}