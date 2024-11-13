#include <iostream>
#include <queue>
using namespace std;
int N, K, sum, answer;
queue<int> q;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;

    for (int i = 0, j; i < K; ++i)
    {
        cin >> j;
        sum += j;
        q.push(j);
    }

    answer = sum;

    for (int i = K, j; i < N; ++i)
    {
        sum -= q.front();
        q.pop();

        cin >> j;
        sum += j;

        q.push(j);

        answer = max(answer, sum);
    }

    cout << answer;
    return 0;
}