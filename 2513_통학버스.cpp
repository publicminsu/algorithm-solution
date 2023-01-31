#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<pair<int, int>> rightPQ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leftPQ;
    int N, K, S;
    cin >> N >> K >> S;
    while (N--)
    {
        pair<int, int> i;
        cin >> i.first >> i.second;
        if (i.first > S)
            rightPQ.push(i);
        else
            leftPQ.push(i);
    }
    int ret = 0, student = 0, topN;
    while (!rightPQ.empty())
    {
        auto cur = rightPQ.top();
        rightPQ.pop();
        if (student == 0)
            topN = cur.first;
        student += cur.second;
        if (student > K)
        {
            int dist = topN - S;
            student -= K;
            ret += (dist << 1);
            topN = cur.first;
            dist = topN - S;
            ret += ((student / K) * dist) << 1;
            student %= K;
        }
    }
    if (student > 0)
        ret += (topN - S) << 1;
    student = 0;
    while (!leftPQ.empty())
    {
        auto cur = leftPQ.top();
        leftPQ.pop();
        if (student == 0)
            topN = cur.first;
        student += cur.second;
        if (student > K)
        {
            int dist = S - topN;
            student -= K;
            ret += (dist << 1);
            topN = cur.first;
            dist = S - topN;
            ret += ((student / K) * dist) << 1;
            student %= K;
        }
    }
    if (student > 0)
        ret += (S - topN) << 1;
    cout << ret;
    return 0;
}