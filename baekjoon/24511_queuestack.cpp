#include <iostream>
#include <deque>
using namespace std;
#define SIZE 100000
int N, A[SIZE], C, M;
deque<int> dq;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    for (int i = 0, B; i < N; ++i)
    {
        cin >> B;
        if (!A[i])
        {
            dq.push_back(B);
        }
    }

    cin >> M;

    while (M--)
    {
        cin >> C;

        dq.push_front(C);
        C = dq.back();
        dq.pop_back();

        cout << C << "\n";
    }

    return 0;
}