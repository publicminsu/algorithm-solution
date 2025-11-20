#include <iostream>
#include <algorithm>

using namespace std;

int T;
string card;
string nums[2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> card;

        for (char &c : card)
        {
            if (c == '6')
            {
                c = '9';
            }
        }

        sort(card.begin(), card.end(), greater<char>());

        for (int i = 0; i < 2; ++i)
        {
            nums[i].clear();
        }

        for (const char &c : card)
        {
            if (nums[0].size() < nums[1].size())
            {
                nums[0].push_back(c);
            }
            else if (nums[1].size() < nums[0].size())
            {
                nums[1].push_back(c);
            }
            else
            {
                (nums[0] < nums[1] ? nums[0] : nums[1]).push_back(c);
            }
        }

        cout << (stoll(nums[0]) * stoll(nums[1])) << "\n";
    }
    return 0;
}