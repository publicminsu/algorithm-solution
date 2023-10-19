#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> nums;
int retMax = INT_MIN, retMin = INT_MAX, N;
void dfs(int idx, int sum, int add, int sub, int multi, int div)
{
    if (idx == N)
    {
        retMax = sum > retMax ? sum : retMax;
        retMin = sum < retMin ? sum : retMin;
        return;
    }
    if (add > 0)
    {
        dfs(idx + 1, sum + nums[idx], add - 1, sub, multi, div);
    }
    if (sub > 0)
    {
        dfs(idx + 1, sum - nums[idx], add, sub - 1, multi, div);
    }
    if (multi > 0)
    {
        dfs(idx + 1, sum * nums[idx], add, sub, multi - 1, div);
    }
    if (div > 0)
    {
        dfs(idx + 1, sum / nums[idx], add, sub, multi, div - 1);
    }
}
int main()
{
    int add, sub, multi, div;
    cin >> N;
    nums = vector<int>(N);
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    cin >> add >> sub >> multi >> div;
    dfs(1, nums[0], add, sub, multi, div);
    cout << retMax << "\n"
         << retMin;
}