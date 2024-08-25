#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
int H, N, Q;
ll sum;
priority_queue<int, vector<int>, greater<int>> pq;
void input()
{
    int value;
    cin >> value;

    pq.push(value);
    sum += value;
}

void check()
{
    if (sum < H)
    {
        cout << -1;
    }
    else
    {
        while (sum - pq.top() >= H)
        {
            sum -= pq.top();
            pq.pop();
        }
        cout << pq.size();
    }

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> H >> N >> Q;

    while (N--)
    {
        input();
    }

    check();
    while (Q--)
    {
        input();
        check();
    }
    return 0;
}