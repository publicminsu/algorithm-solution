#include <iostream>
#include <algorithm>
using namespace std;
int N, K, A;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;

    int gcd = __gcd(N, K);

    for (int i = 0; i < N; ++i)
    {
        cin >> A;

        if ((A - i) % gcd != 0)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}