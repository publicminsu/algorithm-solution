#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<int, int>> v;
    int N, cnt = 1;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end());
    int end = INT_MAX;
    for (auto i : v)
    {
        if (i.first >= end)
        {
            end = i.second;
            ++cnt;
            continue;
        }
        if (i.second < end)
        {
            end = i.second;
        }
    }
    cout << cnt;
    return 0;
}