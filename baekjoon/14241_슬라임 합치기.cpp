#include <iostream>
#include <queue>
using namespace std;
int N, answer;
priority_queue<int> pq;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        int i;
        cin >> i;
        pq.push(i);
    }

    while (pq.size() != 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        answer += first * second;
        pq.push(first + second);
    }

    cout << answer;
    return 0;
}