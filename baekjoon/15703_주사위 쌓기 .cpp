#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<int, int>;
int N, curCnt, answer;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;
        pq.push({0, j});
    }

    int index = 0;

    while (!pq.empty())
    {
        pii next = pq.top();
        pq.pop();

        if (next.first >= answer)
        {
            ++answer;
            curCnt = 0;
        }

        if (next.second >= curCnt)
        {
            ++curCnt;
        }
        else
        {
            pq.push({next.first + 1, next.second});
        }
    }

    cout << answer;
    return 0;
}