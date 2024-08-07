#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nums;
bool isVisited[10];
int cmd;
void dfs(int num)
{
    nums.push_back(num);

    for (int i = 1; i <= 9; ++i)
    {
        if (isVisited[i])
        {
            continue;
        }

        int nextNum = num * 10 + i;

        if (nextNum > 987654321)
        {
            break;
        }

        isVisited[i] = true;

        nums.push_back(nextNum);

        dfs(nextNum);

        isVisited[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    dfs(0);

    sort(nums.begin(), nums.end());

    while (cin >> cmd)
    {
        auto i = upper_bound(nums.begin(), nums.end(), cmd);

        cout << (i == nums.end() ? 0 : *i) << "\n";
    }
    return 0;
}