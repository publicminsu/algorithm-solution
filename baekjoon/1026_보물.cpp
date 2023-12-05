#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A, B;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, ret = 0;
    cin >> N;
    A = B = vector<int>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    for (int i = 0; i < N; ++i)
    {
        ret += A[i] * B[i]; // 큰 값 * 작은 값
    }
    cout << ret;
    return 0;
}