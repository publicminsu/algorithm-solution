#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> numV, minTree, maxTree;
ll minInit(int start, int end, int node)
{
    if (start == end)
        return minTree[node] = numV[start];
    int mid = (start + end) >> 1;
    return minTree[node] = min(minInit(start, mid, node << 1), minInit(mid + 1, end, (node << 1) + 1));
}
ll maxInit(int start, int end, int node)
{
    if (start == end)
        return maxTree[node] = numV[start];
    int mid = (start + end) >> 1;
    return maxTree[node] = max(maxInit(start, mid, node << 1), maxInit(mid + 1, end, (node << 1) + 1));
}
ll minFind(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
        return 1000000001;
    if (start >= left && end <= right)
        return minTree[node];
    int mid = (start + end) >> 1;
    return min(minFind(start, mid, node << 1, left, right), minFind(mid + 1, end, (node << 1) + 1, left, right));
}
ll maxFind(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
        return 0;
    if (start >= left && end <= right)
        return maxTree[node];
    int mid = (start + end) >> 1;
    return max(maxFind(start, mid, node << 1, left, right), maxFind(mid + 1, end, (node << 1) + 1, left, right));
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, M;
    cin >> N >> M;
    minTree = maxTree = vector<ll>((N << 2));
    numV.push_back(0);
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        numV.push_back(num);
    }
    minInit(1, N, 1);
    maxInit(1, N, 1);
    for (int i = 0; i < M; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << minFind(1, N, 1, l, r) << " " << maxFind(1, N, 1, l, r) << "\n";
    }
}