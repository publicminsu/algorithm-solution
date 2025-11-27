#include <iostream>

using namespace std;

int N, K;
int A[10000];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
}

void sort()
{
    int count = 0;

    for (int i = N - 1; i >= 0; --i)
    {
        int lastNum = A[i];

        int maxNum = 0;
        int maxIdx;

        for (int j = 0; j < i; ++j)
        {
            if (A[j] > maxNum)
            {
                maxNum = A[j];
                maxIdx = j;
            }
        }

        if (lastNum < maxNum)
        {
            swap(A[i], A[maxIdx]);
            ++count;

            if (count == K)
            {
                cout << A[maxIdx] << " " << A[i];
                return;
            }
        }
    }

    cout << -1;
}

int main()
{
    input();
    sort();
    return 0;
}