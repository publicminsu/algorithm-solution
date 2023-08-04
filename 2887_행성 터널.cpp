#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <iterator>
using namespace std;
struct planet
{
    int x, y, z;
};
typedef pair<int, int> pii;
vector<int> isVisited;
vector<planet> planets;
multimap<int, int> xm, ym, zm;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int abs(int num)
{
    return num < 0 ? -num : num;
}
pii getLeftValue(multimap<int, int> &m, int curPos)
{
    multimap<int, int>::iterator originIter = m.find(curPos);
    for (auto iter = originIter; iter != m.end(); ++iter)
    {
        pii cur = *iter;
        if (isVisited[cur.second])
            continue;
        return {abs(cur.first - curPos), cur.second};
    }
    return {0, 100001};
}
pii getRightValue(multimap<int, int> &m, int curPos)
{
    multimap<int, int>::reverse_iterator reverseIter(m.find(curPos));
    for (auto iter = reverseIter; iter != m.rend(); ++iter)
    {
        pii cur = *iter;
        if (isVisited[cur.second])
            continue;
        return {abs(cur.first - curPos), cur.second};
    }
    return {0, 100001};
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, ret = 0;
    cin >> N;
    isVisited = vector<int>(N);
    for (int i = 0, x, y, z; i < N; ++i)
    {
        cin >> x >> y >> z;
        planets.push_back({x, y, z});
        xm.insert({x, i});
        ym.insert({y, i});
        zm.insert({z, i});
    }
    pq.push({0, 0});
    while (!pq.empty())
    {
        pii curNode = pq.top();
        pq.pop();
        int curIdx = curNode.second;
        if (isVisited[curIdx])
            continue;
        isVisited[curIdx] = true;
        int curValue = curNode.first;
        ret += curValue;
        pii xLeftValue = getLeftValue(xm, planets[curIdx].x);
        pii xRightValue = getRightValue(xm, planets[curIdx].x);
        pii yLeftValue = getLeftValue(ym, planets[curIdx].y);
        pii yRightValue = getRightValue(ym, planets[curIdx].y);
        pii zLeftValue = getLeftValue(zm, planets[curIdx].z);
        pii zRightValue = getRightValue(zm, planets[curIdx].z);
        if (xLeftValue.second != 100001)
            pq.push(xLeftValue);
        if (xRightValue.second != 100001)
            pq.push(xRightValue);
        if (yLeftValue.second != 100001)
            pq.push(yLeftValue);
        if (yRightValue.second != 100001)
            pq.push(yRightValue);
        if (zLeftValue.second != 100001)
            pq.push(zLeftValue);
        if (zRightValue.second != 100001)
            pq.push(zRightValue);
    }
    cout << ret;

    return 0;
}