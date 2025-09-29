#include <iostream>
using namespace std;

long N, X, answer;
long A[100000];

long calcEdgeCount(long start)
{
    long diff = abs(A[start] - A[start + 1]);

    return max(X - diff, 0L);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> X;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    answer = min(calcEdgeCount(0), calcEdgeCount(N - 2));

    for (int i = 0; i < N - 2; ++i)
    {
        long middleValue = max(A[i], A[i + 2]) + X;
        answer = min(answer, max(0L, middleValue - A[i + 1]));

        long sideValue = A[i + 1] + X;
        answer = min(answer, max(0L, sideValue - A[i]) + max(0L, sideValue - A[i + 2]));

        long left1 = max(A[i + 1], A[i] + X);
        long left2 = max(A[i + 2], left1 + X);
        answer = min(answer, left1 - A[i + 1] + left2 - A[i + 2]);

        long right1 = max(A[i + 1], A[i + 2] + X);
        long right2 = max(A[i], right1 + X);
        answer = min(answer, right1 - A[i + 1] + right2 - A[i]);
    }

    cout << answer;
    return 0;
}