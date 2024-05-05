#include <iostream>
#include <vector>
using namespace std;
int N, curNum, numIdx = 0;
bool checkPrint, checkNum;
string exp;
vector<char> ops;
vector<int> nums;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> exp;

    for (const char &c : exp)
    {
        if (c <= '9' && c >= '0')
        {
            curNum = curNum * 10 + (c - '0');
            checkNum = true;
        }
        else
        {
            if (c == 'C')
            {
                checkPrint = true;
            }
            if (checkNum)
            {
                nums.push_back(curNum);
                checkNum = false;
            }
            ops.push_back(c);

            curNum = 0;
        }
    }
}
void solve()
{
    if (!checkPrint)
    {
        cout << "NO OUTPUT";
        return;
    }

    curNum = nums.front();
    for (const char &c : ops)
    {
        switch (c)
        {
        case 'S':
            curNum -= nums[++numIdx];
            break;
        case 'M':
            curNum *= nums[++numIdx];
            break;
        case 'U':
            curNum /= nums[++numIdx];
            break;
        case 'P':
            curNum += nums[++numIdx];
            break;
        case 'C':
            cout << curNum << " ";
            break;
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}