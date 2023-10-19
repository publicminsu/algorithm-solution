#include <iostream>
#include <vector>
using namespace std;
vector<int> nums, tree;
int N, ret = 0;
int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = start;
    int mid = (start + end) / 2, nextNode = node * 2;
    int leftIdx = init(start, mid, nextNode), rightIdx = init(mid + 1, end, nextNode + 1);
    return tree[node] = (nums[leftIdx] > nums[rightIdx] ? rightIdx : leftIdx);
}
int find(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
        return -1;
    if (start >= left && end <= right)
    {
        return tree[node];
    }
    int mid = (start + end) / 2, nextNode = node * 2;
    int leftIdx = find(start, mid, nextNode, left, right), rightIdx = find(mid + 1, end, nextNode + 1, left, right);
    if (leftIdx == -1)
        return rightIdx;
    else if (rightIdx == -1)
        return leftIdx;
    else
        return (nums[leftIdx] > nums[rightIdx] ? rightIdx : leftIdx);
}
void partSolve(int left, int right)
{
    if (left > right)
        return;
    int idx = find(0, N - 1, 1, left, right);
    int area = (right - left + 1) * nums[idx];
    ret = ret > area ? ret : area;
    partSolve(left, idx - 1);
    partSolve(idx + 1, right);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    tree = vector<int>(N * 4);
    init(0, N - 1, 1);
    partSolve(0, N - 1);
    cout << ret;
    return 0;
}