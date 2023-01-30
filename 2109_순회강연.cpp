#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> v(10001, vector<int>());
    int n, ret = 0, topD = 0;
    cin >> n;
    while (n--)
    {
        int p, d;
        cin >> p >> d;
        v[d].push_back(p);
        topD = topD < d ? d : topD;
    }
    priority_queue<int> pq;
    for (int i = topD; i > 0; --i)
    {
        for (int d : v[i])
            pq.push(d);
        if (!pq.empty())
        {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret;
    return 0;
}