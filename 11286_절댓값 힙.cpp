#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int N, x;
    cin >> N;
    while (N--)
    {
        cin >> x;
        if (x)
        {
            pq.push({abs(x), x});
        }
        else
        {
            if (pq.empty())
                cout << 0;
            else
                cout << pq.top().second, pq.pop();
            cout << "\n";
        }
    }
    return 0;
}