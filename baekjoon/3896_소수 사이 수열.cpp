#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 1299710
bool isNotPrime[SIZE];
int T, k;
vector<int> primes;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    primes.reserve(100001);

    for (int i = 2; i * i < SIZE; ++i)
    {
        for (int j = i + i; j < SIZE; j += i)
        {
            isNotPrime[j] = true;
        }
    }

    for (int i = 2; i < SIZE; ++i)
    {
        if (isNotPrime[i])
        {
            continue;
        }
        primes.push_back(i);
    }

    cin >> T;
    while (T--)
    {
        cin >> k;

        int index = lower_bound(primes.begin(), primes.end(), k) - primes.begin();
        if (primes[index] == k)
        {
            cout << 0;
        }
        else
        {
            cout << primes[index] - primes[index - 1];
        }
        cout << "\n";
    }
    return 0;
}