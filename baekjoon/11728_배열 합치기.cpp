#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> nums;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    nums = vector<int>(N + M);

    for (int i = 0; i < N + M; ++i)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for (const int &num : nums)
    {
        cout << num << " ";
    }
    return 0;
}