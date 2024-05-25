#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int T, K;
ll answer;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        answer = 0;
        cin >> K;

        while (K--)
        {
            int size;
            cin >> size;
            pq.push(size);
        }

        while (pq.size() > 1)
        {
            ll first = pq.top();
            pq.pop();
            ll second = pq.top();
            pq.pop();

            ll sum = first + second;
            pq.push(sum);
            answer += sum;
        }

        pq.pop();

        cout << answer << "\n";
    }
    return 0;
}