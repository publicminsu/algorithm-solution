#include <iostream>
using namespace std;
int T, n;
bool isNotPrime[10001];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;

    for (int i = 2; i * i < 10001; ++i)
    {
        if (isNotPrime[i])
        {
            continue;
        }

        for (int j = i + i; j < 10001; j += i)
        {
            isNotPrime[j] = true;
        }
    }

    while (T--)
    {
        cin >> n;

        int a = 0, b = n;

        for (int i = 2; i * 2 <= n; ++i)
        {
            if (isNotPrime[i])
            {
                continue;
            }

            int j = n - i;

            if (isNotPrime[j])
            {
                continue;
            }

            if ((j - i) < (b - a))
            {
                a = i;
                b = j;
            }
        }

        cout << a << " " << b << "\n";
    }
    return 0;
}