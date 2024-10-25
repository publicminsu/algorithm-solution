#include <iostream>
#include <vector>
using namespace std;
int N, K, size;
vector<int> A;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;
    A = vector<int>(N);
    for (int &a : A)
    {
        cin >> a;
    }

    while (N--)
    {
        int maxIndex = 0;
        int maxNum = A[0];

        for (int i = 1; i <= N; ++i)
        {
            if (A[i] < maxNum)
            {
                continue;
            }

            maxNum = A[i];
            maxIndex = i;
        }

        if (maxIndex == N)
        {
            continue;
        }

        swap(A[maxIndex], A[N]);
        if (!--K)
        {
            for (int &a : A)
            {
                cout << a << " ";
            }
        }
    }

    if (K > 0)
    {
        cout << -1;
    }
    return 0;
}