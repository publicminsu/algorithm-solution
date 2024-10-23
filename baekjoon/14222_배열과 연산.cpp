#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A;
int N, K;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;

    A = vector<int>(N);
    for (int &a : A)
    {
        cin >> a;
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; ++i)
    {
        if (i + 1 == A[i])
        {
            continue;
        }

        if (i + 1 < A[i])
        {
            cout << 0;
            return 0;
        }

        A[i] += K;
        sort(A.begin() + i, A.end());
        --i;
    }
    cout << 1;
    return 0;
}