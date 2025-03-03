#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100000], B[100000];
int resultA[100000], resultB[100000];
int iA, iB, sA, sB, eA, eB, cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + N);

    eA = eB = N - 1;

    while (iA < N && iB < N)
    {
        if (A[iA] == B[iB])
        {
            resultA[sA++] = A[iA++];
            resultB[sB++] = B[iB++];
            ++cnt;
        }
        else if (A[iA] < B[iB])
        {
            resultA[eA--] = A[iA++];
        }
        else
        {
            resultB[eB--] = B[iB++];
        }
    }

    while (iA < N)
    {
        resultA[sA++] = A[iA++];
    }

    while (iB < N)
    {
        resultB[sB++] = B[iB++];
    }

    cout << cnt << "\n";

    for (int i = 0; i < N; ++i)
    {
        cout << resultA[i] << " ";
    }

    cout << "\n";

    for (int i = 0; i < N; ++i)
    {
        cout << resultB[i] << " ";
    }

    return 0;
}