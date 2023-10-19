#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int n;
ull numArr[100000], tree[400000], ret;
int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = start;
    int mid = (start + end) >> 1, nextNode = node << 1;
    int l = init(start, mid, nextNode);
    int r = init(mid + 1, end, nextNode | 1);
    return tree[node] = (numArr[l] < numArr[r] ? l : r);
}
ull find(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
    {
        return 100000;
    }
    if (start >= left && end <= right)
    {
        return tree[node];
    }
    int mid = (start + end) >> 1;
    int nextNode = node << 1;

    int leftIdx = find(start, mid, nextNode, left, right);
    int rightIdx = find(mid + 1, end, nextNode | 1, left, right);

    if (leftIdx == 100000)
        return rightIdx;
    else if (rightIdx == 100000)
        return leftIdx;
    else
        return numArr[leftIdx] < numArr[rightIdx] ? leftIdx : rightIdx;
}
void sizeFind(int start, int end)
{
    if (start > end)
        return;
    int idx = find(0, n - 1, 1, start, end);
    ret = max(ret, numArr[idx] * (end - start + 1));
    sizeFind(start, idx - 1), sizeFind(idx + 1, end);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> numArr[i];
        }
        ret = 0;
        init(0, n - 1, 1);
        sizeFind(0, n - 1);
        cout << ret << "\n";
    }
}