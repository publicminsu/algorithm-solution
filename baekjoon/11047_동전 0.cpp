#include <iostream>
using namespace std;
int A[10], N, K, ret = 0;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = N - 1; i >= 0; --i)
    {
        int div = K / A[i];
        if (!div)
            continue;
        ret += div;
        K %= A[i];
    }
    cout << ret;
    return 0;
}