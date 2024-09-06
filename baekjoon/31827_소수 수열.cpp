#include <iostream>
using namespace std;
bool isNotPrime[1000001];
int N, K;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    isNotPrime[0] = isNotPrime[1] = true;

    for (int i = 2; i * i <= 1000000; ++i)
    {
        if (isNotPrime[i])
        {
            continue;
        }

        for (int j = i + i; j <= 1000000; j += i)
        {
            isNotPrime[j] = true;
        }
    }

    cin >> N >> K;

    for (int i = 2; i <= 1000000; ++i)
    {
        if (isNotPrime[i])
        {
            continue;
        }

        if (i % K == 1)
        {
            cout << i << " ";

            if (--N == 0)
            {
                break;
            }
        }
    }
    return 0;
}