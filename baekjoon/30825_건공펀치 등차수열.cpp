#include <iostream>

using namespace std;

long long N, K, nextA, A, cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    cin >> A;
    nextA = A + K;

    for (int i = 1; i < N; ++i)
    {
        cin >> A;

        if (A > nextA)
        {
            cnt += (A - nextA) * i;
            nextA = A + K;
        }
        else
        {
            cnt += nextA - A;
            nextA += K;
        }
    }

    cout << cnt;
    return 0;
}