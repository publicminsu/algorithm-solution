#include <iostream>
#include <vector>
using namespace std;
int M, N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> M >> N;
    vector<bool> isNotPrime(N + 1);
    isNotPrime[1] = true;
    for (int i = 2; i * i <= N; ++i)
        if (!isNotPrime[i])
            for (int j = i * i; j <= N; j += i)
            {
                isNotPrime[j] = true;
            }
    while (M <= N)
    {
        if (!isNotPrime[M])
            cout << M << "\n";
        ++M;
    }
    return 0;
}