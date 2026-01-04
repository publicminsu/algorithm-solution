#include <iostream>
using namespace std;

int N;
int opposites[6] = {5, 3, 4, 1, 2, 0};
int nums[10001][6];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int &num : nums[i])
        {
            cin >> num;
        }
    }
}

int getMaxSide(int diceIdx, int upIdx)
{
    int downIdx = opposites[upIdx];
    int maxNum = 0;

    for (int i = 0; i < 6; ++i)
    {
        if (downIdx == i || upIdx == i)
        {
            continue;
        }

        maxNum = max(maxNum, nums[diceIdx][i]);
    }

    return maxNum;
}

int findIdx(int diceIdx, int value)
{
    for (int i = 0; i < 6; ++i)
    {
        if (nums[diceIdx][i] == value)
        {
            return i;
        }
    }

    return 1;
}

void solve()
{
    int maxSum = 0;

    for (int i = 0; i < 6; ++i)
    {
        int sum = 0;
        int upIdx = i;

        for (int j = 0; j < N; ++j)
        {
            sum += getMaxSide(j, upIdx);

            upIdx = opposites[findIdx(j + 1, nums[j][upIdx])];
        }

        maxSum = max(maxSum, sum);
    }

    cout << maxSum;
}

int main()
{
    input();
    solve();
    return 0;
}