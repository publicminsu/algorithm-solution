#include <iostream>
#include <queue>
#include <vector>
#define maxNum 100001
using namespace std;
bool isVisted[maxNum];
int dx[] = {1, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int N, K;
    cin >> N >> K;
    pq.push({0, N});
    while (!pq.empty())
    {
        auto cur = pq.top();
        if (cur.second == K)
            break;
        pq.pop();
        int nextNum = cur.second << 1;
        if (nextNum < maxNum && !isVisted[nextNum])
        {
            isVisted[nextNum] = true;
            pq.push({cur.first, nextNum});
        }
        for (int i = 0; i < 2; ++i)
        {
            nextNum = cur.second + dx[i];
            if (nextNum >= 0 && nextNum < maxNum && !isVisted[nextNum])
            {
                isVisted[nextNum] = true;
                pq.push({cur.first + 1, nextNum});
            }
        }
    }
    cout << pq.top().first;
    return 0;
}