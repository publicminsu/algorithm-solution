#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    priority_queue<int> nPQ, pPQ;
    int N, x;
    cin >> N;
    while (N--)
    {
        cin >> x;
        if (x)
        {
            if (x > 0)
                pPQ.push(-x);
            else
                nPQ.push(x);
        }
        else
        {
            if (pPQ.empty() || nPQ.empty())
                if (pPQ.empty() && nPQ.empty())
                    cout << 0;
                else if (pPQ.empty())
                    cout << nPQ.top(), nPQ.pop();
                else
                    cout << -pPQ.top(), pPQ.pop();
            else if (pPQ.top() > nPQ.top())
                cout << -pPQ.top(), pPQ.pop();
            else
                cout << nPQ.top(), nPQ.pop();
            cout << "\n";
        }
    }
    return 0;
}