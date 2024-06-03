#include <iostream>
using namespace std;
int N, L;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> L;

    for (int i = L; i <= 100; ++i)
    {
        int l = (i - 1) * i / 2;
        int n = N - l;

        if (n < 0)
        {
            continue;
        }

        if (n % i == 0)
        {
            int start = n / i;

            while (i--)
            {
                cout << start++ << " ";
            }
            return 0;
        }
    }

    cout << -1;
    return 0;
}