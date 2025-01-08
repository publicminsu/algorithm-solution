#include <iostream>
#include <vector>
using namespace std;
#define SIZE 100001
using ll = long long;
int T, K;
bool isNotPrime[SIZE];
vector<int> primes;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    isNotPrime[0] = isNotPrime[1] = true;

    for (int i = 2; i * i < SIZE; ++i)
    {
        for (int j = i * i; j < SIZE; j += i)
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
        cin >> K;

        ll answer = 987654321;

        for (int i = 0; i < primes.size(); ++i)
        {
            for (int j = i + 1; j < primes.size(); ++j)
            {
                ll value = (ll)primes[i] * primes[j];

                if (answer < value)
                {
                    break;
                }

                if (value < K)
                {
                    continue;
                }

                answer = min(answer, value);
            }
        }

        cout << answer << "\n";
    }
    return 0;
}