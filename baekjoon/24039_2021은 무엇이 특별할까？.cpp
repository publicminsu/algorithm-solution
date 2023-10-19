#include <iostream>
using namespace std;
int N, prevPrime = 2, ret;
bool isNotPrime[10001];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 2; i * i <= 10000; ++i)
    {
        if (isNotPrime[i])
            continue;
        for (int j = i + i; j <= 10000; j += i)
        {
            isNotPrime[j] = true;
        }
    }
    for (int i = 3; i <= 10000; ++i)
    {
        if (isNotPrime[i])
            continue;
        ret = prevPrime * i;
        if (ret > N)
            break;
        prevPrime = i;
    }
    cout << ret;
    return 0;
}