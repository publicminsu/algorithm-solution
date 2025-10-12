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

    cout << nums[1];
    return 0;
}