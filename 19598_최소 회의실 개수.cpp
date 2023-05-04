#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, ret = 0;
    cin >> N;
    vector<pii> v(N);
    priority_queue<int, vector<int>, greater<int>> pq; // 끝점을 저장한다.
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second);
    ret = 1;
    for (int i = 1; i < v.size(); ++i)
    {
        int start = v[i].first, end = v[i].second;
        while (pq.top() <= start)
        {
            pq.pop();
            if (pq.empty())
                break;
        }
        pq.push(end);

        ret = max(ret, int(pq.size()));
    }
    cout << ret;
    return 0;
}