#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, K, sum;
    priority_queue<int> pq;
    cin >> N >> M >> K;
    sum = M * K;
    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        pq.push(j);
    }
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        sum -= cur;
        if (sum <= 0)
            break;
    }
    if (sum > 0)
        cout << "STRESS";
    else
        cout << N - pq.size();
    return 0;
}