#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int N, K;
ll T;
int A[200000];
priority_queue<int> pq;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K >> T;

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    sort(A, A + N);

    int index = 0;

    while (K--)
    {
        while (index < N && A[index] < T)
        {
            pq.push(A[index]);
            ++index;
        }

        if (pq.empty())
        {
            break;
        }

        T += pq.top();
        pq.pop();
    }

    cout << T;
    return 0;
}