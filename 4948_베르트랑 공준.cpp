#include <iostream>
using namespace std;
bool isNotPrime[246913];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    isNotPrime[1] = true;
    for (int i = 2; i * i < 246913; ++i)
        for (int j = i + i; j < 246913; j += i)
            isNotPrime[j] = true;
    while (true)
    {
        cin >> n;
        if (!n)
            break;
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; ++i)
            if (!isNotPrime[i])
                ++cnt;
        cout << cnt << "\n";
    }
    return 0;
}