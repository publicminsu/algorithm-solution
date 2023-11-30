#include <iostream>
#include <string>
using namespace std;
int nums[10], ret;
string N;
int main()
{
    cin >> N;

    for (char c : N)
    {
        ++nums[c - '0'];
    }

    for (int i = 0; i < 6; ++i)
    {
        ret = max(ret, nums[i]);
    }
    for (int i = 7; i < 9; ++i)
    {
        ret = max(ret, nums[i]);
    }
    ret = max(ret, (nums[6] + nums[9] + 1) / 2);

    cout << ret;
    return 0;
}