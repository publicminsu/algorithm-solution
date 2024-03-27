#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pii = pair<int, int>;
int N, curTime;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    vector<pii> works(N);
    for (pii &work : works)
    {
        cin >> work.second >> work.first;
    }
    sort(works.begin(), works.end(), greater<pii>());
    curTime = works.front().first;
    for (const pii &work : works)
    {
        if (curTime < work.first)
        {
            curTime -= work.second;
        }
        else
        {
            curTime = work.first - work.second;
            if (curTime < 0)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << curTime;
    return 0;
}