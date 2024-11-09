#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int T, N;
ll answer;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;
    while (T--)
    {
        answer = 1;

        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            ll j;
            cin >> j;
            pq.push(j);
        }

        while (pq.size() > 1)
        {
            ll i = pq.top();
            pq.pop();
            ll j = pq.top();
            pq.pop();

            ll k = i * j;
            pq.push(k);
            answer = (answer * (k % 1000000007)) % 1000000007;
        }

        pq.pop();
        cout << answer << "\n";
    }
    return 0;
}