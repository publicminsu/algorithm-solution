#include <iostream>
#include <algorithm>
using namespace std;

int nums[3];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int &num : nums)
    {
        cin >> num;
    }

    sort(nums, nums + 3);

    for (const int &num : nums)
    {
        cout << num << " ";
    }

    return 0;
}