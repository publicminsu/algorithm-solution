#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int N, cnt = 0, sum = 0;
    cin >> N;
    vector<bool> isPrime(N + 1, true);
    vector<int> primeNum;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i)
        for (int j = (i << 1); j <= N; j += i)
            isPrime[j] = false;
    for (int i = 2; i <= N; ++i)
        if (isPrime[i])
            primeNum.push_back(i);
    for (int start = 0, end = 0; end < primeNum.size(); ++end)
    {
        sum += primeNum[end];
        while (sum > N)
            sum -= primeNum[start++];
        if (sum == N)
            ++cnt;
    }
    cout << cnt;
    return 0;
}