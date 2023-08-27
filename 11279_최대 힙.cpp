#include <iostream>
#include <queue>
using namespace std;
int N, i;
priority_queue<int> pq;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> i;
        if (i)
            pq.push(i);
        else if (pq.empty())
            cout << 0 << "\n";
        else
            cout << pq.top() << "\n", pq.pop();
    }
    return 0;
}