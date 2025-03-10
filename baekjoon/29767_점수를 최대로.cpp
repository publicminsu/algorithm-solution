#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int N, K;
ll answer;
ll A[300000];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;

    cin >> A[0];

    for (int i = 1; i < N; ++i)
    {
        cin >> A[i];
        A[i] += A[i - 1];
    }

    sort(A, A + N, greater<ll>());

    for (int i = 0; i < K; ++i)
    {
        answer += A[i];
    }

    cout << answer;
    return 0;
}