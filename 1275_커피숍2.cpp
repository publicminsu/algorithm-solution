#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> nums, tree;
ll init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = nums[start];
    int mid = (start + end) >> 1;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
ll find(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
        return 0;
    if (start >= left && end <= right)
        return tree[node];
    int mid = (start + end) >> 1;
    return find(start, mid, node * 2, left, right) + find(mid + 1, end, node * 2 + 1, left, right);
}
void update(int start, int end, int node, int target, ll diff)
{
    if (start > target || end < target)
        return;
    tree[node] += diff;
    if (start != end)
    {
        int mid = (start + end) >> 1;
        update(start, mid, node * 2, target, diff);
        update(mid + 1, end, node * 2 + 1, target, diff);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    nums.push_back(0);
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    tree = vector<ll>((N << 2));
    init(1, N, 1);
    for (int i = 0; i < Q; ++i)
    {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y)
        {
            ll tmp = x;
            x = y;
            y = tmp;
        }
        cout << find(1, N, 1, x, y) << "\n";
        ll diff = b - nums[a];
        nums[a] = b;
        update(1, N, 1, a, diff);
    }
}