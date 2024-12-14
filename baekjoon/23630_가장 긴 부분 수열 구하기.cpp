#include <iostream>
using namespace std;
#define LIMIT 1000001
int N, answer, cnt;
int A[LIMIT];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    for (int i = 1; i < LIMIT; i <<= 1)
    {
        cnt = 0;

        for (int j = 0; j < N; ++j)
        {
            if (A[j] & i)
            {
                ++cnt;
            }
        }

        answer = max(answer, cnt);
    }

    cout << answer;
    return 0;
}