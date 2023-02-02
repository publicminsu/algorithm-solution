#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < N; ++i)
    {
        pair<int, int> j;
        cin >> j.first >> j.second;
        v.push_back(j);
    }
    int L, P, cur = 0, ret = -1;
    sort(v.begin(), v.end());
    cin >> L >> P;
    pq.push({P, 0});
    while (!pq.empty() && cur < L)
    {
        cur += pq.top().first;
        pq.pop();
        ++ret;
        while (!v.empty() && cur >= v.front().first)
        {
            pq.push({v.front().second, v.front().first});
            v.erase(v.begin());
        }
    }
    if (cur < L)
        cout << -1;
    else
        cout << ret;
}