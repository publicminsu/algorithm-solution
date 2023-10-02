#include <iostream>
using namespace std;
typedef unsigned long long ull;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ull ret = 1, N;
    cin >> N;
    for (int i = 2; i <= N; ++i)
    {
        ret *= i;
        while (!(ret % 10))
            ret /= 10;
        ret %= 10000000000000;
    }
    ret %= 10;
    cout << ret;
}