#include <iostream>
using namespace std;

int N;
int A[500001];
long long sum;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    sum = A[N - 1];

    for (int i = N - 2; i >= 0; --i)
    {
        A[i] = min(A[i], A[i + 1]);
        sum += A[i];
    }

    cout << sum;
    return 0;
}