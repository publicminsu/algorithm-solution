#include <iostream>
using namespace std;

int N;
int A[100001];

int gcd(const int &a, const int &b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> A[0];

    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    int gcdValue = abs(A[0] - A[1]);

    for (int i = 1; i < N; ++i)
    {
        gcdValue = gcd(gcdValue, abs(A[i + 1] - A[i]));
    }

    cout << gcdValue;
    return 0;
}