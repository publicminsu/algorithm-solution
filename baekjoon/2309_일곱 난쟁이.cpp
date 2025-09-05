#include <iostream>
#include <algorithm>
using namespace std;

int nums[9];
int sum;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int &num : nums)
    {
        cin >> num;
        sum += num;
    }

    sort(nums, nums + 9);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = i + 1; j < 9; ++j)
        {
            if (sum - nums[i] - nums[j] == 100)
            {
                for (int k = 0; k < 9; ++k)
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }

                    cout << nums[k] << "\n";
                }
                return 0;
            }
        }
    }
    return 0;
}