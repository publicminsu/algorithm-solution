#include <iostream>
using namespace std;
using ll = long long;

int N;
int A[50];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
}

ll calcCnt()
{
    ll cnt = 0;

    for (int i = 1; i < N - 1; ++i)
    {
        int diff = A[i] - (A[i - 1] + A[i + 1]) / 2;

        if (diff <= 0)
        {
            continue;
        }

        A[i] -= diff;
        cnt += diff;
    }

    return cnt;
}

ll calcTotalCnt()
{
    if (N <= 2)
    {
        return 0;
    }

    long long totalCnt = 0;

    while (true)
    {
        ll cnt = calcCnt();

        if (cnt == 0)
        {
            break;
        }

        totalCnt += cnt;
    }

    return totalCnt;
}

int main()
{
    input();
    cout << calcTotalCnt();
    return 0;
}