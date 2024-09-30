#include <iostream>
#include <vector>
using namespace std;
#define LIMIT 1000001
vector<int> primes;
bool isNotPrime[LIMIT]{true, true};
int n;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 2; i * i < LIMIT; ++i)
    {
        for (int j = i + i; j < LIMIT; j += i)
        {
            isNotPrime[j] = true;
        }
    }

    for (int i = 2; i < LIMIT; ++i)
    {
        if (isNotPrime[i])
        {
            continue;
        }

        primes.push_back(i);
    }

    while (cin >> n)
    {
        if (!n)
        {
            break;
        }

        for (const int &prime : primes)
        {
            int other = n - prime;

            if (isNotPrime[other])
            {
                continue;
            }

            cout << n << " = " << prime << " + " << other << "\n";
            break;
        }
    }
    return 0;
}