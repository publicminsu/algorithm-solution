#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;

ll nums[3];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (ll &num : nums)
    {
        cin >> num;
    }

    cout << max(nums[0] * nums[1] / nums[2], nums[0] * nums[2] / nums[1]);
    return 0;
}