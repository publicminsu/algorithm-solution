#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 20000
int A[SIZE], B[SIZE];
int T, N, M, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        answer = 0;

        cin >> N >> M;
        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }
        for (int i = 0; i < M; ++i)
        {
            cin >> B[i];
        }

        sort(B, B + M);

        for (int i = 0; i < N; ++i)
        {
            auto iter = lower_bound(B, B + M, A[i]); // A[i] 이상인 것 찾기
            answer += (iter - B);
        }

        cout << answer << "\n";
    }
    return 0;
}