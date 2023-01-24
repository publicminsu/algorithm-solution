#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int> hpq;
    priority_queue<int, vector<int>, greater<int>> lpq;
    int N;
    cin >> N;
    while (N--)
    {
        int num;
        cin >> num;
        if (hpq.empty() || hpq.top() > num)
        {
            hpq.push(num);
        }
        else
        {
            lpq.push(num);
        }
        if (lpq.size() > hpq.size())
        {
            hpq.push(lpq.top());
            lpq.pop();
        }
        else if (hpq.size() > lpq.size() + 1)
        {
            lpq.push(hpq.top());
            hpq.pop();
        }
        cout << hpq.top() << "\n";
    }
    return 0;
}