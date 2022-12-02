#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int>> pq;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            int output = 0;
            if (!pq.empty())
            {
                output = pq.top();
                pq.pop();
            }
            cout << output << '\n';
        }
        else
        {
            pq.push(x);
        }
    }
    return 0;
}