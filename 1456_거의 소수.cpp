#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull A, B, cnt = 0;
bool isNotPrime[10000001];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B;
    for (ull i = 2; i * i <= B; ++i)
    {
        if (isNotPrime[i])
            continue;
        for (ull j = i * i; j <= B / j; j += i)
            isNotPrime[j] = true;
        for (ull j = i; j <= B / i; j *= i)
        {
            if (j * i < A)
                continue;
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}