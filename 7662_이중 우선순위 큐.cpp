#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        priority_queue<int> hq;
        priority_queue<int, vector<int>, greater<int>> lq;
        unordered_map<int, int> um;
        int k;
        cin >> k;
        while (k--)
        {
            char com;
            int num;
            cin >> com >> num;
            if (com == 'I')
            {
                ++um[num];
                hq.push(num);
                lq.push(num);
            }
            else
            {
                if (num == 1)
                {
                    while (!hq.empty() && !um[hq.top()])
                        hq.pop();
                    if (hq.empty())
                        continue;
                    --um[hq.top()];
                    hq.pop();
                }
                else
                {
                    while (!lq.empty() && !um[lq.top()])
                        lq.pop();
                    if (lq.empty())
                        continue;
                    --um[lq.top()];
                    lq.pop();
                }
            }
        }
        while (!hq.empty() && !um[hq.top()])
            hq.pop();
        if (hq.empty())
        {
            cout << "EMPTY\n";
            continue;
        }
        while (!lq.empty() && !um[lq.top()])
            lq.pop();
        cout << hq.top() << " " << lq.top() << "\n";
    }

    return 0;
}