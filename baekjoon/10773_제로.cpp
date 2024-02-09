#include <iostream>
#include <vector>
using namespace std;
int K, num;
vector<int> nums;
long long sum;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> K;
    nums.reserve(K);

    while (K--)
    {
        cin >> num;
        if (num)
        {
            nums.push_back(num);
        }
        else
        {
            nums.pop_back();
        }
    }

    for (int num : nums)
    {
        sum += num;
    }
    cout << sum;
    return 0;
}