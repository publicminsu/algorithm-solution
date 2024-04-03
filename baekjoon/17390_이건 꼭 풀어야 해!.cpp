#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, Q, L, R;
vector<int> A;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> Q;

    A = vector<int>(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for (int i = 1; i <= N; ++i)
    {
        A[i] += A[i - 1];
    }

    while (Q--)
    {
        cin >> L >> R;
        cout << A[R] - A[L - 1] << "\n";
    }
    return 0;
}