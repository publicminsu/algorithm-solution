#include <iostream>
using namespace std;
int N, M, B, idx, A[51], answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    while (M--)
    {
        cin >> B;
        while (true)
        {
            if (idx == N)
            {
                break;
            }

            if (B > A[idx])
            {
                answer += A[idx];
                ++idx;
            }
            else
            {
                A[idx] -= B;
                break;
            }
        }
    }
    while (idx < N)
    {
        answer += A[idx++];
    }
    cout << answer;
    return 0;
}