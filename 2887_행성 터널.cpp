#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct planet
{
    int x, y, z;
};
typedef pair<int, int> pii;
struct comp
{
    bool operator()(const pii &a, const int &b)
    {
        return a.first < b;
    }
    bool operator()(const int &a, const pii &b)
    {
        return a < b.first;
    }
};
int N, ret = 0;
vector<int> isVisited;
vector<planet> planets;
vector<pii> xv, yv, zv;
priority_queue<pii, vector<pii>, greater<pii>> pq;
pii getLeftValue(vector<pii> &v, int idx)
{
    int curPos = v[idx].first;
    for (int i = idx; i >= 0; --i)
    {
        pii cur = v[i];
        if (isVisited[cur.second])
            continue;
        return {abs(cur.first - curPos), cur.second};
    }
    return {0, 100001};
}
pii getRightValue(vector<pii> &v, int idx)
{
    int curPos = v[idx].first;
    for (int i = idx; i < N; ++i)
    {
        pii cur = v[i];
        if (isVisited[cur.second])
            continue;
        return {abs(cur.first - curPos), cur.second};
    }
    return {0, 100001};
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    isVisited = vector<int>(N);
    for (int i = 0, x, y, z; i < N; ++i)
    {
        cin >> x >> y >> z;
        planets.push_back({x, y, z});
        xv.push_back({x, i});
        yv.push_back({y, i});
        zv.push_back({z, i});
    }
    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());
    sort(zv.begin(), zv.end());
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
        int xPos = planets[curIdx].x, yPos = planets[curIdx].y, zPos = planets[curIdx].z;
        int xIdx = lower_bound(xv.begin(), xv.end(), xPos, comp()) - xv.begin();
        int yIdx = lower_bound(yv.begin(), yv.end(), yPos, comp()) - yv.begin();
        int zIdx = lower_bound(zv.begin(), zv.end(), zPos, comp()) - zv.begin();
        pii xLeftValue = getLeftValue(xv, xIdx);
        pii xRightValue = getRightValue(xv, xIdx);
        pii yLeftValue = getLeftValue(yv, yIdx);
        pii yRightValue = getRightValue(yv, yIdx);
        pii zLeftValue = getLeftValue(zv, zIdx);
        pii zRightValue = getRightValue(zv, zIdx);
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