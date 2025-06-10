#include <iostream>
using namespace std;

int nums[5];
int answer = 987654321;

int gcd(const int &a, const int &b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int &num : nums)
    {
        cin >> num;
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = i + 1; j < 5; ++j)
        {
            int lcm1 = nums[i] * nums[j] / gcd(nums[i], nums[j]);
            for (int k = j + 1; k < 5; ++k)
            {
                int lcm2 = lcm1 * nums[k] / gcd(lcm1, nums[k]);
                answer = min(answer, lcm2);
            }
        }
    }

    cout << answer;
    return 0;
}