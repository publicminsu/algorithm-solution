#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> time;
    cin >> N;
    while (N--)
    {
        int s, e;
        cin >> s >> e;
        time.push_back({s, e});
    }
    sort(time.begin(), time.end());
    pq.push(time[0].second);
    for (int i = 1; i < time.size(); ++i)
    {
        if (pq.top() <= time[i].first)
        {
            pq.pop();
        }
        pq.push(time[i].second);
    }
    cout << pq.size();
    return 0;
}