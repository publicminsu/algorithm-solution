#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int n, m;
ll answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while (n--)
    {
        int a;
        cin >> a;
        pq.push(a);
    }

    while (m--)
    {
        ll a1 = pq.top();
        pq.pop();

        ll a2 = pq.top();
        pq.pop();

        ll newA = a1 + a2;
        pq.push(newA);
        pq.push(newA);
    }

    while (!pq.empty())
    {
        answer += pq.top();
        pq.pop();
    }

    cout << answer;
    return 0;
}