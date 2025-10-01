#include <iostream>
#include <set>

using namespace std;

set<int> nums;
int cnts[7];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 3; ++i)
    {
        int num;
        cin >> num;
        nums.insert(num);
        ++cnts[num];
    }

    switch (nums.size())
    {
    case 1:
        cout << 10000 + *(nums.begin()) * 1000;
        break;
    case 2:
        for (int num : nums)
        {
            if (cnts[num] == 2)
            {
                cout << 1000 + (num * 100);
                break;
            }
        }
        break;
    default:
        cout << *(prev(nums.end())) * 100;
        break;
    }
    return 0;
}